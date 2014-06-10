/***********************************************************************
* Program: encrypt
* Author:  Joshua Jolley
* Summary: encrypts a message with the given key and multiplyer
************************************************************************/

#include <iostream>
using namespace std;

void getKey (int &key, int &multiplyer);
void encrypt(char message[], int key, int multiplyer);
void display (char message[]);

/**********************************************************************
 * MAIN: This function calls 3 functions:
 *    getKey:     Prompt the user for the secret key
 *    encrypt:    encrypts a message using the key and multiplyer
 *    display:    Display the encrypted message
 ***********************************************************************/
int main()
{
   int key;
   int multiplyer;
   char message[256] = {};

   //get the message
   cout << "Enter the message you want to encrypt\n";
   cin.getline(message,256);  

   //confirm the message
   cout << "The message is: "<< message << endl;
   
   //get the key
   getKey(key, multiplyer);

   // convert the top secret message to the plain-text message
   encrypt(message, key, multiplyer);

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
 * encrypt
 * Converts the message by applying key and multiplyer
 **********************************************************************/
void encrypt (char message[], int key, int multiplyer)
{
   for (int i = 0; message[i]; i++)
   {
      if (message[i] == ' ')
         continue;
      message[i] = ((multiplyer * (message[i] - 65) + key) % 26) + 65;
   }
   cout << endl;
}


/**********************************************************************
 * display
 * Displays the message on screen
 **********************************************************************/
void display (char message[])
{
   cout << "The translated message is: \"" <<  message << "\"\n";
}
