#pragma once
#include <stdint.h>

// Define MT19937 constants (32-bit RNG)
typedef enum {
  // Assumes W = 32 (omitting this)
  N = 624,
  M = 397,
  R = 31,
  A = 0x9908B0DF,
  F = 1812433253,
  U = 11,
  // Assumes D = 0xFFFFFFFF (omitting this)
  S = 7,
  B = 0x9D2C5680,
  T = 15,
  C = 0xEFC60000,
  L = 18,
  MASK_LOWER = (1ull << R) - 1,
  MASK_UPPER = (1ull << R)
} mt19937_enum;

typedef struct {

  uint32_t mt[N];
  uint16_t index;

} mt19937_ctx;

uint32_t ExtractU32(mt19937_ctx *ctx) ;
void Twist(mt19937_ctx *ctx);
void Initialize(mt19937_ctx *ctx, const uint32_t seed) ;