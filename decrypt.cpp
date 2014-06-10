/***********************************************************************
* Program:
*    Assignment 11, Functions
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
* Summary: 
*    This program is designed to store a secret message.  The message
*    is encrypted using the Caesar Cipher: a simple cipher that simply
*    adds 3 to ASCII value of the message.  For example, if the plain-text
*    message is "SECRET", the cipher text is "VHFUHW" because
*                 'V' = 'S' + 3
*                 'H' = 'E' + 3
*                 ...
*    Thus, if I am to decrypt the message, I simply subtract three from
*    each letter.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      Switching from perl to c++
************************************************************************/

#include <iostream>
using namespace std;

void getKey (int &key, int & multiplyer);
bool keyCorrect (int key);
void decrypt(char message[], int key, int multiplyer);
void display (char message[]);

/**********************************************************************
 * MAIN: This function calls 4 functions:
 *    getKey:     Prompt the user for the secret key
 *    keyCorrect: Determines if the user's guess is correct
 *    convert:    Convert our cipher text to plain text so the world can see
 *    display:    Display the converted message
 ***********************************************************************/
int main()
{
   // the key the user will guess
   int key;
   int multiplyer;
   // the top secret message
   char message[256] = {};

   //get the message
   cout << "Enter the message you want to encrypt\n";
   cin.getline(message,256); 

   cout << "The message is: "<< message << endl;
   
   getKey(key,multiplyer);
   // convert the top secret message to the plain-text message
   decrypt(message, key, multiplyer);

   // show the user
   display(message);
      
   return 0;
}

/**********************************************************************
 * getKey
 * Prompt for a key and return it.
 *********************************************************************/
void getKey (int &key, int &multiplyer)
{
   cout << "Please enter the key to encrypt the message: ";
   cin >> key;

   cout << "Please enter the multiplyer to encrypt the message: ";
   cin >> multiplyer;
   return;
}


/**********************************************************************
 * decrypt
 * Converts the message by subtracting the value of key from the letters.
 **********************************************************************/
void decrypt(char message[], int key, int multiplyer)
{
   for (int i = 0; message[i]; i++)
   {
      if (message[i] == ' ')
         continue;
      message[i] = (((message[i] - 65 - key)/multiplyer + 26) % 26) + 65;
   }   
}


/**********************************************************************ome

 * display
 * Displays the message on screen
 **********************************************************************/
void display (char message[])
{
   cout << "The original message is  : \"" <<  message << "\"\n";
}

int gcd(int a, int b)
for(int i=1;i<=a&&i<=b;i++)
{ 
 
 if(a %i == 0 && (b % i == 0) ) //this checks if variable i divides both numbers fully
 {  
 
    gcd=i; 
   }
} 