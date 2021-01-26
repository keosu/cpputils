#include <iostream>
#include <strutils.hpp>
int main(int argc, char** argv) {
  std::string s = "abc def fad df\t fs abdef";
  auto text = strutil::split(s);

  std::copy(text.begin(), text.end(),
            std::ostream_iterator<std::string>(std::cout, "\n"));

  std::cout << '\n';

  return 0;
}