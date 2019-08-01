/**
  * Author:		Joe Dunton
  *  * File:		rot13.cpp
  *  * Desc:		This file handles the caesar cipher functionality of cipherize
**/

//includes
#include <cstdlib>
#include <iostream>

//local includes
#include "cipherize.h"
#include "caesar.h"

//using decs
using std::cout;
using std::cin;
using std::string;
using std::flush;
using std::endl;

//prototypes
void rot13();
void rot13Again();
void rot13Help();
string rot13Encode(string plaintext);

void rot13(){
	int select;
        string input;
        system ("clear && tput setaf 5");
        cout << "\n\nSelect option and press enter: " << endl;
        system ("tput setaf 1");
        cout << "1) Decode" << endl;
        system ("tput setaf 2");
        cout << "2) Encode" << endl;
        system ("tput setaf 3");
        cout << "3) Help" << endl;
        system ("tput sgr0 && tput civis");
        cout << "\n\n>> " << flush;
        cin >> select;
        switch (select){
                case 1:
                        cout << "Enter ciphertext to decode: " << flush;
                        getchar();
                        getline(cin, input);
                        cout << "\nDecoded ciphertext is: " << rot13Encode(input) << endl;
                        system ("tput sgr0 && tput civis");
                        break;
                case 2:
                        cout << "Enter plaintext to encode: " << flush;
                        cin >> input;
                        cout << "\nEncoded ciphertext is: " << flush;
                        system ("tput setaf 2");
                        cout << rot13Encode(input) << endl;
                        system ("tput sgr0 && tput civis");
                        break;
                case 3:
                        cipherHelp("rot13");
                        break;
        }
        rot13Again();
}

string rot13Encode(string plaintext){
	return caesarEncode(plaintext, 13);
}

void rot13Help(){
	cout << "Dis cipher sux" << endl;
}

void rot13Again(){
	char choice;
        cout << "\nUse rot13 again? [" << flush;
        system ("tput setaf 2");
        cout << "y" << flush;
        system ("tput sgr0");
        cout << "/" << flush;
        system ("tput setaf 1");
        cout << "n" << flush;
        system ("tput sgr0");
        cout << "]: " << flush;

        cin >> choice;
        if(choice == 'y'){
                rot13();
        }
        else if (choice == 'n'){
                cipherize();
        }
        else{
                cout << "Please enter y or n." << flush;
                rot13Again();
        }
}
