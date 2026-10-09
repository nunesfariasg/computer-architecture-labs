#include "decoder.h"

DecoderResult decoder_2_to_4(Bit a, Bit b) {
    DecoderResult result;

    // Each output represents one unique input combination.
    result.y0 = !a & !b;
    result.y1 = !a & b;
    result.y2 = a & !b;
    result.y3 = a & b;

    return result;
}