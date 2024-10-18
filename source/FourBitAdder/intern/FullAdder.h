#ifndef FULLADDER_H
#define FULLADDER_H

#include "HalfAdder.h"

/**
 * @class FullAdder
 * @brief A class that represents a full adder circuit.
 *
 * A full adder takes in two bits and a carry-in bit, producing a sum and a carry-out bit.
 */
class FullAdder {
private:
    HalfAdder ha1, ha2; ///< Two Half Adders used for the full adder logic
    OR orGate;          ///< OR gate for carry-out
public:
    unsigned short sum; ///< The sum output of the full adder
    unsigned short carry; ///< The carry output of the full adder

    /**
     * @brief Constructs a FullAdder instance.
     * @param id The identifier used to initialize the internal gates.
     */
    FullAdder(unsigned short id)
        : ha1(id), ha2(id + 1), orGate(id + 2) {}

    /**
     * @brief Computes the sum and carry of the full adder.
     *
     * @param A The first input bit.
     * @param B The second input bit.
     * @param Cin The carry-in bit.
     * 
     * This function calculates the sum and carry outputs based on the input bits and carry-in.
     */
    void compute(unsigned short A, unsigned short B, unsigned short Cin) {
        // First Half Adder
        ha1.compute(A, B);

        // Second Half Adder
        ha2.compute(ha1.sum, Cin);

        // Sum is the output of the second Half Adder
        sum = ha2.sum;

        // Carry-out = Carry from the first Half Adder OR Carry from the second Half Adder
        orGate.set_in1(ha1.carry);
        orGate.set_in2(ha2.carry);
        carry = orGate.out();
    }
};

#endif // FULLADDER_H
