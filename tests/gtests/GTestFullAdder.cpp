#include <gtest/gtest.h>
#include "../../source/FourBitAdder/intern/FullAdder.h"

TEST(FullAdderTest, ComputeSumAndCarry) {
    FullAdder fullAdder(1);

    // Test case: A = 0, B = 0, Cin = 0 -> Sum = 0, Carry = 0
    fullAdder.compute(0, 0, 0);
    EXPECT_EQ(fullAdder.sum, 0);
    EXPECT_EQ(fullAdder.carry, 0);

    // Test case: A = 0, B = 1, Cin = 0 -> Sum = 1, Carry = 0
    fullAdder.compute(0, 1, 0);
    EXPECT_EQ(fullAdder.sum, 1);
    EXPECT_EQ(fullAdder.carry, 0);

    // Test case: A = 1, B = 0, Cin = 0 -> Sum = 1, Carry = 0
    fullAdder.compute(1, 0, 0);
    EXPECT_EQ(fullAdder.sum, 1);
    EXPECT_EQ(fullAdder.carry, 0);

    // Test case: A = 1, B = 1, Cin = 0 -> Sum = 0, Carry = 1
    fullAdder.compute(1, 1, 0);
    EXPECT_EQ(fullAdder.sum, 0);
    EXPECT_EQ(fullAdder.carry, 1);

    // Test case: A = 0, B = 0, Cin = 1 -> Sum = 1, Carry = 0
    fullAdder.compute(0, 0, 1);
    EXPECT_EQ(fullAdder.sum, 1);
    EXPECT_EQ(fullAdder.carry, 0);

    // Test case: A = 0, B = 1, Cin = 1 -> Sum = 0, Carry = 1
    fullAdder.compute(0, 1, 1);
    EXPECT_EQ(fullAdder.sum, 0);
    EXPECT_EQ(fullAdder.carry, 1);

    // Test case: A = 1, B = 0, Cin = 1 -> Sum = 0, Carry = 1
    fullAdder.compute(1, 0, 1);
    EXPECT_EQ(fullAdder.sum, 0);
    EXPECT_EQ(fullAdder.carry, 1);

    // Test case: A = 1, B = 1, Cin = 1 -> Sum = 1, Carry = 1
    fullAdder.compute(1, 1, 1);
    EXPECT_EQ(fullAdder.sum, 1);
    EXPECT_EQ(fullAdder.carry, 1);
}
