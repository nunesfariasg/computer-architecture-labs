#include <stdio.h>

#include "logic-gates/logic_gate.h"
#include "circuits/combinational/half-adder/half_adder.h"
#include "circuits/combinational/full-adder/full_adder.h"
#include "circuits/combinational/four-bit-adder/four_bit_adder.h"
#include "circuits/combinational/multiplexer/multiplexer.h"
#include "circuits/combinational/decoder/decoder.h"
#include "circuits/sequential/latch/sr_latch.h"
#include "circuits/sequential/flip-flop/sr_flip_flop.h"

void print_truth_table(void) {

    printf("A B | AND OR XOR NAND\n");
    printf("---------------------\n");

    for (Bit a = 0; a <= 1; a++) {
        for (Bit b = 0; b <= 1; b++) {

            printf(
                "%d %d |  %d   %d   %d    %d\n",
                a,
                b,
                gate_and(a, b),
                gate_or(a, b),
                gate_xor(a, b),
                gate_nand(a, b)
            );
        }
    }
}

void print_not_table(void) {

    printf("A | NOT\n");
    printf("-------\n");

    for (Bit a = 0; a <= 1; a++) {

        printf(
            "%d |  %d\n",
            a,
            gate_not(a)
        );
    }
}

void print_half_adder_table(void) {

    printf("A B | SUM CARRY\n");
    printf("----------------\n");

    for (Bit a = 0; a <= 1; a++) {
        for (Bit b = 0; b <= 1; b++) {

            HalfAdderResult result = half_adder(a, b);

            printf(
                "%d %d |  %d    %d\n",
                a,
                b,
                result.sum,
                result.carry
            );
        }
    }
}

void print_full_adder_table(void) {

    printf("A B Cin | SUM CARRY\n");
    printf("--------------------\n");

    for (Bit a = 0; a <= 1; a++) {
        for (Bit b = 0; b <= 1; b++) {
            for (Bit carry_in = 0; carry_in <= 1; carry_in++) {

                FullAdderResult result =
                    full_adder(a, b, carry_in);

                printf(
                    "%d %d  %d  |  %d    %d\n",
                    a,
                    b,
                    carry_in,
                    result.sum,
                    result.carry
                );
            }
        }
    }
}

void print_four_bit_adder_test(void) {

    Bit a[4] = {1, 1, 0, 1}; // 1011 = 11
    Bit b[4] = {0, 1, 1, 0}; // 0110 = 6

    FourBitAdderResult result =
        four_bit_adder(a, b, 0);

    printf("A:          ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", a[i]);
    }

    printf("\nB:          ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", b[i]);
    }

    printf("\nCarry in:   0");

    printf("\nResult:     %d", result.carry_out);

    for (int i = 3; i >= 0; i--) {
        printf("%d", result.sum[i]);
    }

    printf("\n");
}

void print_mux_truth_table(void) {
    printf("A B S | Y\n");
    printf("------------\n");

    for (Bit a = 0; a <= 1; a++) {
        for (Bit b = 0; b <= 1; b++) {
            for (Bit s = 0; s <= 1; s++) {
                printf(
                    "%d %d %d | %d\n",
                    a, b, s,
                    mux_2to1(a, b, s)
                );
            }
        }
    }

    printf("\n");

}

void print_decode_truth_table(void) {
    printf("A B | Y0 Y1 Y2 Y3\n");
    printf("---------------------\n");

    for (Bit a = 0; a <= 1; a++) {
        for (Bit b = 0; b <= 1; b++) {
            DecoderResult result = decoder_2_to_4(a, b);

            printf(
                "%d %d |  %d  %d  %d  %d\n",
                a, b,
                result.y0,
                result.y1,
                result.y2,
                result.y3
            );
        }
    }
}

void print_latch_truth_table(void) {
    printf("S R | Q\n");
    printf("--------\n");

    SRLatchResult result;

    result = sr_latch(0, 0, 0);
    printf("0 0 | %d\n", result.q);

    result = sr_latch(1, 0, 0);
    printf("1 0 | %d\n", result.q);

    result = sr_latch(0, 0, 1);
    printf("0 0 | %d\n", result.q);

    printf("\n");
}

void print_flip_flop_truth_table(void) {

    Bit previous_clk = 0;
    Bit previous_q = 0;

    printf("CLK S R | Q Q_NOT\n");
    printf("-----------------\n");

    // Each step represents a new clock level and input combination.
    Bit clocks[] = {0, 1, 1, 0, 1, 1, 0, 1};
    Bit sets[]   = {0, 1, 1, 0, 0, 0, 0, 0};
    Bit resets[] = {0, 0, 0, 0, 1, 1, 0, 0};

    int size = sizeof(clocks) / sizeof(clocks[0]);

    for (int i = 0; i < size; i++) {
        SRFlipFlopResult result = sr_flip_flop(
            sets[i],
            resets[i],
            clocks[i],
            previous_clk,
            previous_q
        );

        printf(
            " %d   %d %d | %d %d\n",
            clocks[i],
            sets[i],
            resets[i],
            result.q,
            result.q_not
        );

        previous_clk = clocks[i];
        previous_q = result.q;
    }
}

int main(void) {

    printf("==========================================\n");
    printf("Digital Circuits Lab\n");
    printf("==========================================\n\n");

    printf("------------------------------------------\n");
    printf("LOGIC GATES\n");
    printf("------------------------------------------\n");

    print_truth_table();

    printf("\n");

    print_not_table();

    printf("------------------------------------------\n");
    printf("COMBINATIONAL CIRCUITS\n");
    printf("------------------------------------------\n\n");

    printf("\nHALF ADDER\n");
    printf("------------------------------------------\n");

    print_half_adder_table();

    printf("\nFULL ADDER\n");
    printf("------------------------------------------\n");

    print_full_adder_table();

    printf("\nFOUR-BIT ADDER\n");
    printf("------------------------------------------\n");

    print_four_bit_adder_test();

    printf("\nMULTIPLEXER 2:1\n");
    printf("------------------------------------------\n");

    print_mux_truth_table();

    printf("2-to-4 DECODER\n");
    printf("------------------------------------------\n");

    print_decode_truth_table();

    printf("------------------------------------------\n");
    printf("SEQUENTIAL CIRCUITS\n");
    printf("------------------------------------------\n");

    printf("\nLATCH SR\n");
    printf("------------------------------------------\n");

    print_latch_truth_table();

    printf("SR FLIP-FLOP\n");
    printf("------------------------------------------\n");

    print_flip_flop_truth_table();

    return 0;
}