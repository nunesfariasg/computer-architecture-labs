#include "sr_latch.h"

SRLatchResult sr_latch(Bit s, Bit r, Bit q_prev) {
    SRLatchResult result;

    // Both inputs active is an invalid state for a NOR SR latch.
    if (s && r) {
        result.q = q_prev;
        result.q_not = !q_prev;
        return result;
    }

    // Set stores 1; reset stores 0; otherwise, retain the previous state.
    result.q = s || (!r && q_prev);
    result.q_not = !result.q;

    return result;
}