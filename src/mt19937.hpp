#pragma once
#include <cinttypes>
#include <cstdio>

class mtrand
{
private:
  // Some ugly constants...
  // Assumes W = 32 (omitting this)
  const static int N = 624;
  const static int M = 397;
  const static int R = 31;
  const static int A = 0x9908B0DF;
  const static int F = 1812433253;
  const static int U = 11;
  // Assumes D = 0xFFFFFFFF (omitting this)
  const static int S = 7;
  const static int B = 0x9D2C5680;
  const static int T = 15;
  const static int C = 0xEFC60000;
  const static int L = 18;
  const static int MASK_LOWER = (1ull << R) - 1;
  const static int MASK_UPPER = (1ull << R);

  uint32_t mt[N];
  uint16_t index;

  void twist()
  {
    uint32_t i, x, xA;
    for (i = 0; i < N; i++)
    {
      x = (this->mt[i] & MASK_UPPER) + (this->mt[(i + 1) % N] & MASK_LOWER);
      xA = x >> 1;
      if (x & 0x1)
        xA ^= A;
      this->mt[i] = this->mt[(i + M) % N] ^ xA;
    }
    this->index = 0;
  };

public:
  mtrand(const uint32_t seed)
  {
    uint32_t i;

    this->mt[0] = seed;

    for (i = 1; i < N; i++)
    {
      this->mt[i] = (F * (this->mt[i - 1] ^ (this->mt[i - 1] >> 30)) + i);
    }

    this->index = N;
  };
  uint32_t rand(uint32_t range) { return (this->rand()) % range; };
  uint32_t rand(void)
  {
    uint32_t y;
    int i = this->index;

    if (this->index >= N)
    {
      this->twist();
      i = this->index;
    }

    y = this->mt[i];
    this->index = i + 1;

    y ^= (this->mt[i] >> U);
    y ^= (y << S) & B;
    y ^= (y << T) & C;
    y ^= (y >> L);

    return y;
  };
};
