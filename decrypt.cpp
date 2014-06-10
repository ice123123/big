/***********************************************************************
* Program: decrypt
* Author: Joshua Jolley
* Summary: decrypt a message when you know the key and the multiplyer     
************************************************************************/

#include <iostream>
using namespace std;

void getKey (int &key, int & multiplyer);
void decrypt(char message[], int key, int multiplyer);
void display (char message[]);

/**********************************************************************
 * MAIN: This function calls 3 functions:
 *    getKey:     Prompt the user for the secret key
 *    decrypt:    Convert our cipher text to plain text so the world can see
 *    display:    Display the converted message
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
   
   //get the key and the multiplyer
   getKey(key,multiplyer);

   // convert the top secret message to the plain-text message
   decrypt(message, key, multiplyer);

   // show the user
   display(message);
      
   return 0;
}

/**********************************************************************
 * getKey
 * Prompt for a key and multiplyer
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
 * Converts the message.  This function doesn't work in most cases. (yet)
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


/**********************************************************************
 * display
 * Displays the message on screen
 **********************************************************************/
void display (char message[])
{
   cout << "The original message is  : \"" <<  message << "\"\n";
}