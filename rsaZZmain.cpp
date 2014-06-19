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

/******************************************************************************
 * Replace all '@' characters in a string with ' ' (space) characters.
 ******************************************************************************/
void replaceAllAtSignsWithSpaces(string &message)
{
   size_t index = 0;
   while ((index = message.find_first_of('@', index)) >= 0 &&
          index <= message.length())
   {
      message.replace(index++, 1, 1, ' ');
   }
}

/******************************************************************************
 * Drive the RSA Encryption/Decryption process.
 ******************************************************************************/
int main(int argc, char *argv[])
{
   if (argc < 2)
   {
      cout << "Usage: " << argv[0] << " message\n";
      return 1;
   }

   if (isalpha(argv[1][0])) // if message is alphabetic (encrypting)
   {
      // Get the message to encrypt
      string message;

      for (int i = 1; i < argc; i++)
      {
         int j = 0;
         while (argv[i][j] != '\0') // until end of word
         {
            if (isalpha(argv[i][j])) // Make sure chars are text
            {
               message += toupper(argv[i][j]);
               j++;
            }
            else
            {
               cerr << "\n--ERROR--  Can only use text and spaces.\n\n";
               return 1;
            }
         }
         if (i != argc - 1) // if not the last word
         {
            message += "@";
         }
      }

      ZZ m = fromBase27(message);
      ZZ p;
      ZZ q;

      findPandQ(m, p, q);

      ZZ n = p * q;
      ZZ t = (p - 1) * (q - 1);
      ZZ e = findE(t);

      ZZ encrypted = modPow(m, e, n);

      cout << encrypted << " " << p << " " << q << " " << e << endl;

      replaceAllAtSignsWithSpaces(message);

      // output verbose results to standard error to not interfere with test
      cerr << endl
           << "Text (base 27) = " << message << endl
           << "Message        = " << m << endl
           << "Encrypted      = " << encrypted << endl
           << endl
           << "p = " << p << endl
           << "q = " << q << endl
           << "n = " << n << endl
           << "t = " << t << endl
           << "e = " << e << endl
           << endl;
   }
   else // if message is a number (decrypting)
   {
      ZZ encrypted = to_ZZ(argv[1]);

      ZZ p = to_ZZ(argv[2]);
      ZZ q = to_ZZ(argv[3]);
      ZZ e = to_ZZ(argv[4]);

      ZZ n = p * q;
      ZZ t = (p - 1) * (q - 1);
      ZZ d = findInverse(e, t);

      ZZ m = modPow(encrypted, d, n);
      string message = toBase27(m);
      replaceAllAtSignsWithSpaces(message);

      cout << message << endl;

      // output verbose results to standard error to not interfere with test
      cerr << endl
           << "Encrypted      = " << encrypted << endl
           << "Message        = " << m << endl
           << "Text (base 27) = " << message << endl
           << endl
           << "p = " << p << endl
           << "q = " << q << endl
           << "n = " << n << endl
           << "t = " << t << endl
           << "e = " << e << endl
           << "d = " << d << endl
           << endl;
   }

   return 0;
}
