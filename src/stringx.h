#include <iostream>
#include <string>
#include <vector>

using namespace std;

class stringx {
 public:
  stringx();
  stringx(string str);
  stringx(const char* chars);
  stringx(const stringx& str);

  stringx operator=(const char* chars) { return stringx(chars); }
  stringx operator+=(const char* chars) {
    _str += chars;
    return *this;
  }
  stringx operator+=(const char c) {
    _str += c;
    return *this;
  }
  bool operator!=(const char* chars) { return !_str.compare(chars); }

  friend ostream& operator<<(ostream& out, stringx& obj) {}

  stringx trim();
  stringx ltrim();
  stringx rtrim();

  bool contains(char c);

  vector<string> split(string delim = " \t\r\n");

  string& str() { return _str; }

 private:
  string _str;
};
