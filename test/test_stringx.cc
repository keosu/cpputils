#include "../include/stringx.hpp"

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  stringx str("  \tabc def gds abc \t\t \n");

  str.trim();
  cout << str << endl;
  vector<string> vec = str.split();
  for (auto i : vec) {
    cout << i << endl;
  }
  cout << "++++++++++++++++++++++++++" << endl;
  stringx x("abc");
  cout << "size of stringx class: " << sizeof(stringx) << endl;
  cout << "abc == abc : " << (x == "abc") << endl;
  cout << "abc == cde : " << (x == "cde") << endl;
  cout << "abc != ABC : " << (x != "abc") << endl;
  cout << "abc != cde : " << (x != "cde") << endl;
}
