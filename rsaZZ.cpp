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
#include <deque>

NTL_CLIENT
const ZZ ZERO = to_ZZ(0);

/******************************************************************************
 * Find b^n % m.
 ******************************************************************************/
ZZ modPow(ZZ b, ZZ n, ZZ m) {
   return PowerMod(b % m, n, m);
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
   deque<char> myDeque;
   while (n != 0)
   {
      int lastDigit = n % 27;
      n /= to_ZZ(27);
      myDeque.push_front((char)(lastDigit + 64));
   }
   string message ="";
   for(std::deque<char>::iterator it = myDeque.begin(); it != myDeque.end(); ++it)
      message += *it;
   return message;

}

/******************************************************************************
 * Find a suitable e for a ZZ number that is the "totient" of two primes.
 ******************************************************************************/
ZZ findE(ZZ t)
{
  for (ZZ i = to_ZZ(3); i < t; i++)
    if (GCD(i,t) == 1)
      return i;
}

/******************************************************************************
 * Find suitable primes p and q for encrypting a ZZ number that is the message.
 ******************************************************************************/
void findPandQ(ZZ m, ZZ &p, ZZ &q)
{
  long length = 0;
  for(; m != 0; m /= 10, length++);
  GenPrime(p, length / 2);
  NextPrime(q, p);
}
