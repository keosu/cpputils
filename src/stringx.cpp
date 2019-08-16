#include "stringx.h"

ostream& operator<<(ostream& out, stringx& obj) {
  out << obj._str;
  return out;
}

stringx::stringx() { _str = ""; }

stringx::stringx(string str) { _str = str; }
stringx::stringx(const char* chars) { _str = chars; }

stringx::stringx(const stringx& str) { _str = str._str; }

stringx stringx::ltrim() {
  if (_str.empty() || !std::isspace(_str.front())) {
    return stringx(_str);
  }
  auto start = _str.find_first_not_of(" \n\t\v\f\r");
  _str = _str.substr(start);
  return *this;
}

stringx stringx::rtrim() {
  if (_str.empty() || !std::isspace(_str.back())) {
    return stringx(_str);
  }
  auto end = _str.find_last_not_of(" \n\t\v\f\r");
  _str = _str.substr(0, end + 1);
  return *this;
}

stringx stringx::trim() {
  this->ltrim();
  this->rtrim();
  return *this;
}

bool stringx::contains(char c) {
  if (_str.find(c) == string::npos) return false;
  return true;
}

vector<string> stringx::split(string delim) {
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