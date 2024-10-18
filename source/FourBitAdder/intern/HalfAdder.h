#ifndef HALFADDER_H
#define HALFADDER_H

#include "LogicGates.h"

/**
 * @class HalfAdder
 * @brief A class that represents a half adder circuit.
 *
 * A half adder takes in two bits and produces a sum and a carry output.
 */
class HalfAdder {
private:
    AND andGate;     ///< AND gate for carry output
    OR orGate;       ///< OR gate for final sum output
    NAND nandGate1;  ///< NAND gate to implement NOT A
    NAND nandGate2;  ///< NAND gate to implement NOT B
    NAND nandGate3;  ///< NAND gate for intermediate sum calculation
public:
    unsigned short sum;   ///< The sum output of the half adder
    unsigned short carry; ///< The carry output of the half adder

    /**
     * @brief Constructs a HalfAdder instance.
     * @param id The identifier used to initialize the internal gates.
     */
    HalfAdder(unsigned short id)
        : andGate(id),
          orGate(id + 1),
          nandGate1(id + 2),
          nandGate2(id + 3),
          nandGate3(id + 4) {}

    /**
     * @brief Computes the sum and carry of the half adder.
     *
     * @param A The first input bit.
     * @param B The second input bit.
     * 
     * This function calculates the sum and carry outputs based on the input bits.
     */
    void compute(unsigned short A, unsigned short B) {
        // NOT A using NAND
        nandGate1.set_in1(A);
        nandGate1.set_in2(A); // NAND(A, A) = NOT A

        // NOT B using NAND
        nandGate2.set_in1(B);
        nandGate2.set_in2(B); // NAND(B, B) = NOT B

        // Intermediate Sum calculation: (A AND NOT B) OR (NOT A AND B)
        andGate.set_in1(A);  // A
        andGate.set_in2(nandGate2.out()); // NOT B

        unsigned short A_AND_NOT_B = andGate.out();

        andGate.set_in1(nandGate1.out()); // NOT A
        andGate.set_in2(B); // B

        unsigned short NOT_A_AND_B = andGate.out();

        orGate.set_in1(A_AND_NOT_B);
        orGate.set_in2(NOT_A_AND_B);
        sum = orGate.out(); // Sum = A XOR B

        // Carry = A AND B
        andGate.set_in1(A);
        andGate.set_in2(B);
        carry = andGate.out(); // Carry = A AND B
    }
};

#endif // HALFADDER_H
