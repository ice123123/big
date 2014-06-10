/*****************************************************
* Program: gcd
* Author:  Joshua Jolley
* Summary: Test program for gcd function
*****************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;


/****************************************************************
* FUNCTION: gcd 
* finds GCD(a, b) and s and t such that sa + tb = GCD(a, b)
****************************************************************/
int gcd(int a, int b, int& s, int& t)
{
	int temp;
    if (b == 0)
    {
       return a;
    }
    else
    {
       a = gcd(b, a % b, s, t);
       temp = s;
       s = t;
       t = temp - (a/b) * t;
       return a;
    }
}

/****************************************************************
* FUNCTION: main 
* Test driver for gcd with interpreted results.
****************************************************************/
int main(int argc, char * argv[])
{
	int s = 0;
	int t = 1;
	if (argc == 3)
	{
		int mygcd = gcd(atoi(argv[1]),atoi(argv[2]),s,t);
		if (mygcd == atoi(argv[1]))
			cout << argv[1] << " is a multple of  " << argv[2] << endl;
		else if (mygcd == atoi(argv[2]))
			cout << argv[2] << " is a multple of " << argv[1] << endl;
		else if (mygcd == 1)
			cout << argv[1] << " and " << argv[2] << " are coprime.\n";
		else
		{
			cout << "s * a + t * b = gcd\n";
			cout <<  s << " * " << argv[1] << " + " << t << "*" << argv[2] << " = " << mygcd << endl;
		}
	}
	else 
		cout << "USAGE: gcd a b\n";

	return 0;
}