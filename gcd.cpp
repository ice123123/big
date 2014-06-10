#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;



// finds GCD(a, b) and s and t such that sa + tb = GCD(a, b)
// (pseudocode for this function can be found in the textbook)
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

// // finds GCD(a, b) and s and t such that sa + tb = GCD(a, b)
// // (pseudocode for this function can be found in the textbook)
// int ext_gcd(int a, int b, int& s, int& t)
// {
// 	int quotient;
//     s = 0;   
//     int old_s = 1;
//     t = 1; 
//     int old_t = 0;
//     int r = b;    
//     int old_r = a;
//     int temp;


//     while (r != 0)
//     {
//         quotient = old_r / r;
//         temp = r;
//         r = old_r - quotient * temp;
//         old_r = temp;

//         temp = s;
//  		s = old_s - quotient * temp;
//  		old_s = temp;

//  		temp = t;
//  		t = old_t - quotient * temp;
//  		old_t = temp;
// 	}

//  	return old_r;
//  }

int main(int argc, char * argv[])
{
	int s = 0;
	int t = 1;
	if (argc == 3)
	{
		int mygcd = gcd(atoi(argv[1]),atoi(argv[2]),s,t);
		if (mygcd == atoi(argv[1]) || mygcd == atoi(argv[2]))
			cout << argv[1] << " and " << argv[2] << " are coprime.\n";
		else if (mygcd == 1)
			cout << "Either " << argv[1] << " or " << argv[2] << " are prime.\n";
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