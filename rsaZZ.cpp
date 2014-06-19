/***********************************************************************
 * Program:
 *    Exploration 3, RSA
 *    Brother Neff, CS237
 *
 * Author:
 *    Brother Neff
 *
 * Summary:
 *    RSA Encryption/Decryption Driver
 *    Compile with:
 *      g++ -c rsaZZmain.cpp
 ***********************************************************************/
#include <cstdlib>
#include <NTL/ZZ.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

NTL_CLIENT
const ZZ ZERO = to_ZZ(0);

/******************************************************************************
 * Find b^n % m.
 ******************************************************************************/
ZZ modPow(ZZ b, ZZ n, ZZ m) {
   return PowerMod(b, n, m);
}

/******************************************************************************
 * Find i such that a * i is congruent to 1 (mod m).
 ******************************************************************************/
ZZ findInverse(ZZ a, ZZ m) {
   return InvMod(a, m);
}

/******************************************************************************
 * Convert from a text message representing a base 27 number to a ZZ number.
 ******************************************************************************/
ZZ fromBase27(string message) //adapted from Ryan Humbert's code
{
   ZZ ZZnum = ZERO;
   ZZ offset = to_ZZ(char('@'));

   for (int i = 0; i < message.length(); i++)
      ZZnum = ZZnum + power_ZZ(27, (message.length() - i - 1)) * (to_ZZ(message[i]) - offset);

   return ZZnum;
}
/******************************************************************************
 * Convert from a ZZ number to a base 27 number represented by a text message.
 ******************************************************************************/
string toBase27(ZZ n)
{
   string message = "";
   while (n != 0)
   {
      int lastDigit = n % 27;
      n /= to_ZZ(27);
      message += (lastDigit > 9) ? (char)(lastDigit + 64) : (char)(lastDigit + 47);
   }
   return message;
}

/******************************************************************************
 * Find a suitable e for a ZZ number that is the "totient" of two primes.
 ******************************************************************************/
ZZ findE(ZZ t)
{
  return to_ZZ(0); 
}

/******************************************************************************
 * Find suitable primes p and q for encrypting a ZZ number that is the message.
 ******************************************************************************/
void findPandQ(ZZ m, ZZ &p, ZZ &q)
{
  return;
}