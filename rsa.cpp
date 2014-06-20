/***********************************************************************
 * RSA Encryption/Decryption
 ***********************************************************************/
#include <cmath>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;


int modPow(int base, int exp, int modulus) {
  base %= modulus;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) 
      result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

// finds GCD(a, b) and s and t such that sa + tb = GCD(a, b)
// (pseudocode for this function can be found in the textbook)
int extendedEuclideanGCD(int a, int b, int &s, int &t)
{
   s = 0;
   int old_s = 1;
   t = 1;
   int old_t = 0;
   int r = b;
   int old_r = a;
   int quotient;
   int temp;
   while (r != 0)
   {
      quotient = old_r / r;

      temp = r;
      r = old_r - quotient * temp;
      old_r = temp;

      temp = s;
      s = old_s - quotient * temp;
      old_s = temp;

      temp = t;
      t = old_t - quotient * temp;
      old_t = temp;
   }
   s = old_s;
   t = old_t;
   return old_r;
}

// finds i such that a * i is congruent to 1 (mod m)
int findInverse(int a, int m)
{
   int s = 0;
   int t = 0;
   int gcd = extendedEuclideanGCD(a, m, s, t);
   assert(gcd == 1);
   if (s < 0)
      s += m;
   return s;

}

/******************************************************************************
 * Run it through its paces.
 ******************************************************************************/
int main(int argc, char *argv[])
{
   if (argc < 5)
   {
      cout << "Usage: " << argv[0] << " p q e message\n";
      return 1;
   }

   int p = atoi(argv[1]);
   int q = atoi(argv[2]);
   int n = p * q;
   int e = atoi(argv[3]);
   int d = 0;

   char *message = argv[4];
   int offset = 'A';    // offset for conversion without spaces
   bool spaces = false; // true => there are spaces in the message

   int length = strlen(message);

   if (isalpha(message[0]))
   {
      int size = (int) (ceil(length / 2.0));
      int numeric[size];
      int number;

      for (int i = 0; i < length; i++)
      {
         // is there a space?
         if (message[i] == ' ')
         {
            spaces = true;
            offset--;
            break;
         }
      }

      cerr << "RSA Encryption:\n\n";

      cerr << "Translate the letters in '" << message << "' into their "
           << "numerical\nequivalents and then group the numbers into "
           << "blocks of four, result is:\n";

      for (int i = 0; i < length; i++)
      {
         message[i] = toupper(message[i]); // Change to all upper case
         if (message[i] == ' ')
         {
            number = 0; // spaces translate as zero
         }
         else
         {
            number = message[i] - offset; // find numeric equivalent
         }
         if (i % 2 == 0)
         {
            numeric[i / 2] = number * 100; // 2 hundreds digits
         }
         else
         {
            numeric[i / 2] += number; // 2 tens digits
         }
      }

      // output the converted letters as a number with leading zeros
      for (int i = 0; i < size; i++)
      {
         cout << setfill('0') << setw(4) << numeric[i] << " ";
      }
      cout << endl;
      cout.flush();

      cerr << "\nEncrypt each block using the mapping C = M^e mod n, ";
      cerr << "result is:\n";

      for (int i = 0; i < size; i++)
      {
         cout << setfill('0') << setw(4) << modPow(numeric[i], e, n)
              << " ";
      }
      cout << endl;
   }
   else
   {
      cerr << "RSA Decryption:\n\n";

      length = argc - 4;
      int numeric[length];

      for (int i = 0; i < length; i++)
      {
         numeric[i] = atoi(argv[i + 4]);
      }

      cerr << "Find the inverse of " << e << " modulo " << p - 1 << " * "
           << q - 1 << " = " << ((p - 1) * (q - 1)) << ", result is: ";
      d = findInverse(e, ((p - 1) * (q - 1)));
      cerr << d << endl << endl;

      cerr << "Decrypt the message ";
      for (int i = 0; i < length; i++)
      {
         cerr << setfill('0') << setw(4) << numeric[i] << " ";
      }

      cerr << "\nusing fast modular exponentiation to compute P = C^"
           << d << " mod " << n << ", result is:\n";

      for (int i = 0; i < length; i++)
      {
         numeric[i] = modPow(numeric[i], d, n);
         cerr << setfill('0') << setw(4) << numeric[i] << " ";
      }
      cerr << endl;
      cerr.flush();

      cerr << "\nTranslate back to English letters, result is:\n";
      cerr.flush();

      if (d > 1000) offset--;

      for (int i = 0; i < length * 2; i++)
      {
         char c = ((i % 2 == 0) ?
                   (numeric[i / 2] / 100) + offset
                   :
                   (numeric[i / 2] % 100) + offset);
         cout << ((c < 'A') ? ' ' : c);
      }
      cout << endl;
   }

   return 0;
}
