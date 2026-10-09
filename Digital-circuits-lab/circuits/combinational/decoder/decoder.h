#ifndef DECODER_H
#define DECODER_H

#include "../../../logic-gates/logic_gate.h"

typedef struct {
    Bit y0;
    Bit y1;
    Bit y2;
    Bit y3;
} DecoderResult;

DecoderResult decoder_2_to_4(Bit a, Bit b);

#endif