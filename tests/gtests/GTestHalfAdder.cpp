#include <gtest/gtest.h>
#include "../../source/FourBitAdder/intern/HalfAdder.h"

TEST(HalfAdderTest, ComputeSumAndCarry) {
    HalfAdder halfAdder(1);

    // Test case: A = 0, B = 0 -> Sum = 0, Carry = 0
    halfAdder.compute(0, 0);
    EXPECT_EQ(halfAdder.sum, 0);
    EXPECT_EQ(halfAdder.carry, 0);

    // Test case: A = 0, B = 1 -> Sum = 1, Carry = 0
    halfAdder.compute(0, 1);
    EXPECT_EQ(halfAdder.sum, 1);
    EXPECT_EQ(halfAdder.carry, 0);

    // Test case: A = 1, B = 0 -> Sum = 1, Carry = 0
    halfAdder.compute(1, 0);
    EXPECT_EQ(halfAdder.sum, 1);
    EXPECT_EQ(halfAdder.carry, 0);

    // Test case: A = 1, B = 1 -> Sum = 0, Carry = 1
    halfAdder.compute(1, 1);
    EXPECT_EQ(halfAdder.sum, 0);
    EXPECT_EQ(halfAdder.carry, 1);
}
