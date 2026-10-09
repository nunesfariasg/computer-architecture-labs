#ifndef SR_LATCH_H
#define SR_LATCH_H

#include "../../../logic-gates/logic_gate.h"

typedef struct {
    Bit q;
    Bit q_not;
} SRLatchResult;

SRLatchResult sr_latch(Bit s, Bit r, Bit q_prev);

#endif