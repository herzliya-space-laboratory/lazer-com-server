#include <gtest/gtest.h>
#include <iostream>
#include <stdio.h>
#include <glog/logging.h>


int main(int argc, char **argv) {
    std::cout << argv[1] << std::endl; 
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

TEST(test, t)
{
}
