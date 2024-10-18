#ifndef FOURBITADDER_H
#define FOURBITADDER_H

#include "./intern/FullAdder.h"

/**
 * @class FourBitAdder
 * @brief A class that represents a four-bit adder circuit.
 *
 * A four-bit adder takes two 4-bit binary numbers and computes their sum, 
 * along with a carry-out if an overflow occurs.
 */
class FourBitAdder {
private:
    FullAdder fa[4]; ///< Array of Full Adders for each bit
public:
    unsigned short sum[4];   ///< Array to hold the sum output
    unsigned short carryOut;  ///< Carry-out output of the four-bit adder

    /**
     * @brief Constructs a FourBitAdder instance.
     *
     * Initializes the four Full Adders needed for the computation.
     */
    FourBitAdder() : fa{FullAdder(1), FullAdder(4), FullAdder(7), FullAdder(10)} {}

    /**
     * @brief Computes the sum of two 4-bit binary numbers.
     *
     * @param A The first 4-bit binary number as an array.
     * @param B The second 4-bit binary number as an array.
     * @param Cin The carry-in bit.
     * 
     * This function calculates the sum of A and B, 
     * storing the result in the sum array and the final carry in carryOut.
     */
    void compute(const unsigned short A[4], const unsigned short B[4], unsigned short Cin) {
        unsigned short carry = Cin; // Initialize carry with Cin
        for (int i = 0; i < 4; ++i) {
            fa[i].compute(A[i], B[i], carry); // Compute using the FullAdder
            sum[i] = fa[i].sum; // Store the sum
            carry = fa[i].carry; // Update carry for the next iteration
        }
        carryOut = carry; // Store the final carry-out
    }
};

#endif // FOURBITADDER_H
