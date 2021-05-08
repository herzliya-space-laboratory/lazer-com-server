#include <gtest/gtest.h>
#include <iostream>
#include <stdio.h>
#include "logger.h"


int main(int argc, char **argv) {
    std::cout << argv[1] << std::endl; 
    LazerComm::logger::init("./logs/", "lazer-comm");

    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

TEST(test, t)
{

}
