#include <iostream>
#include <string>
#include <vector>

using namespace std;

class stringx {
 public:
  stringx() { _str = ""; }

  stringx(string str) { _str = str; }
  stringx(const char* chars) { _str = chars; }

  stringx(const stringx& str) { _str = str._str; }

  stringx operator=(const char* chars) { return stringx(chars); }
  stringx operator+=(const char* chars) {
    _str += chars;
    return *this;
  }
  stringx operator+=(const char c) {
    _str += c;
    return *this;
  }
  bool operator==(const char* chars) { return !_str.compare(chars); }
  bool operator!=(const char* chars) { return _str.compare(chars); }
  char operator[](int index) { return _str[index]; }
  string operator()(int start, int end) {
    return _str.substr(start, end - start + 1);
  }

  friend ostream& operator<<(ostream& out, stringx& obj) {
    out << obj._str;
    return out;
  }

  stringx trim() {
    this->ltrim();
    this->rtrim();
    return *this;
  }
  stringx ltrim() {
    if (_str.empty() || !std::isspace(_str.front())) {
      return stringx(_str);
    }
    auto start = _str.find_first_not_of(" \n\t\v\f\r");
    _str = _str.substr(start);
    return *this;
  }
  stringx rtrim() {
    if (_str.empty() || !std::isspace(_str.back())) {
      return stringx(_str);
    }
    auto end = _str.find_last_not_of(" \n\t\v\f\r");
    _str = _str.substr(0, end + 1);
    return *this;
  }

  bool contains(char c) {
    if (_str.find(c) == string::npos) return false;
    return true;
  }

  vector<string> split(string delim = " \t\r\n") {
    vector<string> vec;

    string tmp = "";
    bool append = false;
    for (auto i = 0; i < _str.size(); i++) {
      if (delim.find(_str[i]) == string::npos) {
        if (append && tmp != "") {
          vec.emplace_back(tmp);
          append = false;
          tmp = "";
        }
        tmp += _str[i];
      } else {
        append = true;
      }
    }
    if (tmp != "") {
      vec.emplace_back(tmp);
      tmp = "";
    }

    return vec;
  }

  string& str() { return _str; }

 private:
  string _str;
};
