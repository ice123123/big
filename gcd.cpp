/*****************************************************
* Program: gcd
* Author:  Joshua Jolley
* Summary: Test program for gcd function
*****************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;


// /****************************************************************
// * FUNCTION: gcd
// * finds GCD(a, b) and s and t such that sa + tb = GCD(a, b)
// ****************************************************************/
// int gcd(int a, int b, int &s, int &t)
// {

//    if (b == 0)
//    {
//       s = tempS;
//       t = tempT;
//       cout << "s: " << s << " t: " << t << endl;
//       return a;
//    }
//    else
//    {
//       a = gcd(b, a % b, s, t);
//       tempS = s;
//       s = t;
//       tempT = t;
//       t = tempS - (a / b) * t;
//       return a;
//    }
// }


/****************************************************************
* FUNCTION: gcd
* finds GCD(a, b) and s and t such that sa + tb = GCD(a, b)
****************************************************************/
int gcd(int a, int b, int &s, int &t)
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
   cout << "Bézout coefficients: " << old_s << " " << old_t << endl;
   cout << "greatest common divisor: " << old_r << endl;
   cout << "quotients by the gcd: " << t << " " << s << endl;
   s = old_s;
   t = old_t;
   cout << "s * a + t * b = gcd\n";

   cout <<  old_s << " * " << a << " + " << old_t << " * " << b << " = " << old_r << endl;
}

/****************************************************************
* FUNCTION: main
* Test driver for gcd with interpreted results.
****************************************************************/
int main(int argc, char *argv[])
{
   int s = 5;
   int t = 7;
   if (argc == 3)
   {
      int mygcd = gcd(atoi(argv[1]), atoi(argv[2]), s, t);
   }
   else
      cout << "USAGE: gcd a b\n";

   return 0;
}