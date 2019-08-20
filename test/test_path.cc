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

TEST(PathLibTest, pathTest) {
  EXPECT_EQ(1, Path::isDIR("/etc"));
  EXPECT_EQ(0, Path::isDIR("/etc/profile"));
  EXPECT_EQ(0, Path::isRegFile("/etc"));
  EXPECT_EQ(1, Path::isRegFile("/etc/profile"));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);  //初始化

  return RUN_ALL_TESTS();
}