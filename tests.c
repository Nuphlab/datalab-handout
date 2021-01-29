/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
// Bit-Level Manipulation Functions
//1
int test_bitAnd(int x, int y)
{
  return x&y;
}
int test_bitOr(int x, int y)
{
  return x|y;
}
//2
int test_copyLSB(int x)
{
  return (x & 0x1) ? -1 : 0;
}
int test_allEvenBits(int x) {
  int i;
  for (i = 0; i < 32; i+=2)
      if ((x & (1<<i)) == 0)
   return 0;
  return 1;
}
//3
int test_logicalShift(int x, int n) {
  unsigned u = (unsigned) x;
  unsigned shifted = u >> n;
  return (int) shifted;
}
//4
int test_bang(int x)
{
  return !x;
}
int test_bitParity(int x) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i++)
    result ^= (x >> i) & 0x1;
  return result;
}
// Arithmetic Functions
//2
int test_isNotEqual(int x, int y)
{
  return x != y;
}
int test_negate(int x) {
  return -x;
}
//3
int test_isPositive(int x) {
  return x > 0;
}
int test_isNonNegative(int x) {
  return x >= 0;
}
int test_rotateLeft(int x, int n) {
  unsigned u = (unsigned) x;
  int i;
  for (i = 0; i < n; i++) {
      unsigned msb = u >> 31;
      unsigned rest = u << 1;
      u = rest | msb;
  }
  return (int) u;
}
int test_addOK(int x, int y)
{
    long long lsum = (long long) x + y;
    return lsum == (int) lsum;
}
//4
int test_absVal(int x) {
  return (x < 0) ? -x : x;
}
int test_isNonZero(int x)
{
  return x!=0;
}
