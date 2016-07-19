#ifndef _EXTINT_H_
#define _EXTINT_H_

#include <stdint.h>

__extension__ typedef __int128 int128_t;
__extension__ typedef unsigned __int128 uint128_t;

#define INT128_MIN ((int128_t) 0 - ((int128_t) 1 << 126) - ((int128_t) 1 << 126))
#define INT128_MAX ((int128_t) -1 + ((int128_t) 1 << 126) + ((int128_t) 1 << 126))
#define UINT128_MAX (((uint128_t) 1 << 127) - (uint128_t) 1 + ((uint128_t) 1 << 127))

#define u128(hi, lo) (((uint128_t) (hi) << 64) + (lo))

#endif // _EXTINT_H_
