#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#ifndef linux
#error "this class works only for Linux"
#endif

using namespace std;

class Path {
 public:
  static bool exist(string path) { return access(path.c_str(), R_OK) == F_OK; }

  static bool isDIR(string path) {
    struct stat s;
    lstat(path.c_str(), &s);
    return S_ISDIR(s.st_mode);
  }

  static bool isRegFile(string path) {
    struct stat s;
    lstat(path.c_str(), &s);
    return S_ISREG(s.st_mode);
  }

  static vector<string> listFiles(string &path, string pattern = ".*") {
    vector<string> vec;

    if (!Path::exist(path) || !Path::isDIR(path)) {
      return vec;
    }
    DIR *dir = opendir(path.c_str());
    if (dir == nullptr) {
      return vec;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
      if (entry->d_type == DT_REG || entry->d_type == DT_UNKNOWN) {
        string name = entry->d_name;
        if (regex_match(name, regex(pattern))) {
          vec.push_back(name);
        }
      }
    }
    closedir(dir);

    sort(vec.begin(), vec.end());

    return vec;
  }

  static vector<string> listFolders(string &path, string pattern = ".*") {
    vector<string> vec;

    if (!Path::exist(path) || !Path::isDIR(path)) {
      return vec;
    }
    DIR *dir = opendir(path.c_str());
    if (dir == nullptr) {
      return vec;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
      if (entry->d_type == DT_DIR) {
        string name = entry->d_name;
        if (regex_match(name, regex(pattern))) {
          vec.push_back(name);
        }
      }
    }
    closedir(dir);

    sort(vec.begin(), vec.end());

    return vec;
  }
};