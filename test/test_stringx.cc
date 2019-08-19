#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "../include/path.hpp"
#include "../include/strings.h"

using namespace std;

int Foo(int a, int b) {
  if (a == 0 || b == 0) {
    throw "don't do that";
  }
  int c = a % b;
  if (c == 0) return b;
  return Foo(b, c);
}

TEST(FooTest, HandleNoneZeroInput) {
  EXPECT_EQ(2, Foo(4, 10));
  EXPECT_EQ(6, Foo(30, 18));
}

TEST(StrTest, strtesttest) {
  stringx x(" abd def \tfef\t\t\n");
  string abc = x.trim().str();
  EXPECT_STREQ("abd def \tfef", abc.c_str());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);  //初始化

  return RUN_ALL_TESTS();
}