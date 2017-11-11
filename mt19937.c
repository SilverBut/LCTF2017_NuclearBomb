
#include "mt19937.h"
#include <stdint.h>
#include <stdio.h>



void Initialize(mt19937_ctx *ctx, const uint32_t seed) {
  uint32_t i;

  ctx->mt[0] = seed;

  for (i = 1; i < N; i++) {
    ctx->mt[i] = (F * (ctx->mt[i - 1] ^ (ctx->mt[i - 1] >> 30)) + i);
  }

  ctx->index = N;
}

void Twist(mt19937_ctx *ctx) {
  uint32_t i, x, xA;
  for (i = 0; i < N; i++) {
    x = (ctx->mt[i] & MASK_UPPER) + (ctx->mt[(i + 1) % N] & MASK_LOWER);
    xA = x >> 1;
    if (x & 0x1)
      xA ^= A;
    ctx->mt[i] = ctx->mt[(i + M) % N] ^ xA;
  }
  ctx->index = 0;
}

// Obtain a 32-bit random number
uint32_t ExtractU32(mt19937_ctx *ctx) {
  uint32_t y;
  int i = ctx->index;

  if (ctx->index >= N) {
    Twist(ctx);
    i = ctx->index;
  }

  y = ctx->mt[i];
  ctx->index = i + 1;

  y ^= (ctx->mt[i] >> U);
  y ^= (y << S) & B;
  y ^= (y << T) & C;
  y ^= (y >> L);

  return y;
}
