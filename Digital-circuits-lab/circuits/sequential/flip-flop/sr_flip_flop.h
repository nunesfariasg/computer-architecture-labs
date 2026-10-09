#ifndef SR_FLIP_FLOP_H
#define SR_FLIP_FLOP_H

#include "../../../logic-gates/logic_gate.h"

typedef struct {
    Bit q;
    Bit q_not;
} SRFlipFlopResult;

SRFlipFlopResult sr_flip_flop(
    Bit s,
    Bit r,
    Bit clk,
    Bit previous_clk,
    Bit previous_q
);

#endif
