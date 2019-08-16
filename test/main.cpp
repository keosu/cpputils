#include "../src/stringx.h"

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
}