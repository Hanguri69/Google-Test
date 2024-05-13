#include "pch.h"
#include <gtest/gtest.h>

#include "Source2.h"  // Include your credit card validation code header here

//isNumberString функцийн тест 
TEST(NumberStringTest, HandlesNumericInput) {
    EXPECT_TRUE(isNumberString("1234567890"));
}


TEST(NumberStringTest, HandlesNonNumericInput) {
    EXPECT_FALSE(isNumberString("1234a56789"));
}


TEST(NumberStringTest, HandlesEmptyInput) {
    EXPECT_FALSE(isNumberString(""));
}

// luhn algorithm-ийн тест 

TEST(LuhnTest, ValidatesCorrectNumber) {
    EXPECT_TRUE(isValidCreditCard("4532015112830366"));  
}

TEST(LuhnTest, InvalidatesIncorrectNumber) {
    EXPECT_FALSE(isValidCreditCard("4532015112830361"));  
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}