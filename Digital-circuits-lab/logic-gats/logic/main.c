#include <stdio.h>
#include "logic_gat.h"

void print_truth_table(void) {
    printf("A B | AND OR XOR NAND\n");
    printf("---------------------\n");

    for (Bit a = 0; a <= 1; a++) {
        for (Bit b = 0; b <= 1; b++) {
            printf(
                "%d %d |  %d   %d   %d    %d\n",
                a,
                b,
                gat_and(a, b),
                gat_or(a, b),
                gat_xor(a, b),
                gat_nand(a, b)
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
            gat_not(a)
        );
    }
}

int main(void) {

    print_truth_table();
    printf("\n");
    print_not_table();

    return 0;
}