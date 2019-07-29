/**
  * Author:		Joe Dunton
  *  * File:		caesar.cpp
  *  * Desc:		This file handles the caesar cipher functionality of cipherize
**/

//includes
#include <cstdlib>
#include <iostream>

//local includes
#include "cipherize.h"

//using decs
using std::cout;
using std::cin;
using std::string;
using std::flush;
using std::endl;

//porotypes
void caesar();
void caesarAgain();
void caesarHelp();
string caesarEncode(string plaintext, int shift);
string caesarDecode(string ciphertext, int shift);

void caesar(){
	int select;
	int shift;
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
			cout << "Enter known shift (1-25) or 0 to bruteforce: " << flush;
			cin >> shift;
                        cout << "\nDecoded ciphertext is: " << caesarDecode(input, shift) << endl;
                        system ("tput sgr0 && tput civis");
                        break;
                case 2:
                        cout << "Enter plaintext to encode: " << flush;
                        cin >> input;
			cout << "Enter shift amount (1-25): " << flush;
			cin >> shift;
				
                        cout << "\nEncoded ciphertext is: " << flush;
                        system ("tput setaf 2");
                        cout << caesarEncode(input, shift) << endl;
                        system ("tput sgr0 && tput civis");
                        break;
                case 3:
                        caesarHelp();
                        break;
        }
        caesarAgain();
}

string caesarEncode(string plaintext, int shift){
	string ciphertext = "";
	for(int i=0;i<plaintext.length();i++){
		if(!(isalpha(plaintext[i]))){
			ciphertext += char(plaintext[i]);
		}
		else{
			if (isupper(plaintext[i])) 
            			ciphertext += char(int(plaintext[i]+shift-65)%26 +65);  
    			else
        			ciphertext += char(int(plaintext[i]+shift-97)%26 +97);
		}	
	}
	return ciphertext;
}

string caesarDecode(string ciphertext, int shift){
	string plaintext = "";
	if(shift > 0)
		plaintext = caesarEncode(ciphertext, 26 - shift);
	else{
		cout << endl;
		for(int i=1;i<26;i++){
			cout << caesarEncode(ciphertext, i) << "\t <- Decoded with shift of " << i << endl;
		}
	}

	return plaintext;
}

void caesarAgain(){
	char choice;
        cout << "\nUse caesar again? [" << flush;
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
                caesar();
        }
        else if (choice == 'n'){
                cipherize();
        }
        else{
                cout << "Please enter y or n." << flush;
                caesarAgain();
        }
}

void caesarHelp(){
	cout << "you've been helped" << endl;
	caesarAgain();
}
