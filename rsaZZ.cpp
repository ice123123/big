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
ZZ modPow(ZZ base, ZZ exponent, ZZ mod)
{
  return PowerMod(base % mod, exponent, mod);
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
ZZ fromBase27(string m) //adapted from Ryan Humbert's code
{
   ZZ num = ZERO;
   ZZ offset = to_ZZ(char('@'));

   for (int i = 0; i < m.length(); i++)
      num = num + power_ZZ(27, (m.length() - i - 1)) * (to_ZZ(m[i]) - offset);

   return num;
}
/******************************************************************************
 * Convert from a ZZ number to a base 27 number represented by a text message.
 ******************************************************************************/
string toBase27(ZZ n)
{
   // deque<char> myDeque;
   // while (n != 0)
   // {
   //    int lastDigit = n % 27;
   //    n /= to_ZZ(27);
   //    myDeque.push_front((char)(lastDigit + 64));
   // }
   // string message = "";
   // for (std::deque<char>::iterator it = myDeque.begin(); it != myDeque.end(); ++it)
   //    message += *it;
   // return message;
   string message ="";
   for (n; n> 0; n /= 27)
      message.insert(0,1, char(rem(n,27) + '@'));
   return message
}

/******************************************************************************
 * Find a suitable e for a ZZ number that is the "totient" of two primes.
 ******************************************************************************/
ZZ findE(ZZ t)
{
   for (ZZ i = to_ZZ(3); i < t; i++)
      if (GCD(i, t) == 1)
         return i;
}

/******************************************************************************
 * Find suitable primes p and q for encrypting a ZZ number that is the message.
 ******************************************************************************/
void findPandQ(ZZ m, ZZ &p, ZZ &q)
{
   long length = 0;
   for (; m != 0; m /= 10, length++);
   GenPrime(p, length * 2);
   GenGermainPrime(q, length * 2);
}
