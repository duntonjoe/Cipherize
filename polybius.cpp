/**
 * Author:		Joe Dunton
 * File:		polybius.cpp
 * Desc:		This file handles the polybius square functionality of cipherize
**/

//includes
#include <iostream>
#include <istream>
#include <ostream>
#include <cstdlib>
#include <cmath>
#include <boost/algorithm/string.hpp>
#include <ctype.h>
//using decs
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::string;
using std::abs;
using std::to_string;

//func protos
string polybiusEncode(string plaintext);
string polybiusDecode(string ciphertext);
void polybiusAgain();

void polybius(){
	int select;
	string input;
	system ("clear && tput setaf 5");
	cout << "\n\nSelect option and press enter: " << endl;
	system ("tput setaf 1");
	cout << "1) Encode" << endl;
	system ("tput setaf 2");
	cout << "2) Decode" << endl;
	system ("tput sgr0 && tput civis");
	cout << "\n\n>> " << flush;
	cin >> select;
	if(select-1){
		cout << "Enter ciphertext to decode: " << flush;
		cin >> input;
		cout << "\nDecoded ciphertext is: " << polybiusDecode(input) << endl;
	}
	else{
		cout << "Enter plaintext to encode: " << flush;
		cin >> input;
		cout << "\nEncoded plaintext is: " << flush;
		system ("tput setaf 2");
		cout << polybiusEncode(input) << endl;
		system ("tput sgr0 && tput civis");
	}
	polybiusAgain();

}

string polybiusEncode(string plaintext){
	string lowPlain = boost::algorithm::to_lower_copy(plaintext);
	string ciphertext = "";
	string unsupported = "";
	int row;
	int col;

	for(int i = 0; lowPlain[i]; i++){
		if(isalnum(lowPlain[i])){
			//handles all letters in the sqaure
			if(lowPlain[i] >= 'a' && lowPlain[i] <= 'z'){
				row = ceil((lowPlain[i] - 'a') / 6) + 1;  
				col = ((lowPlain[i] - 'a') % 6) + 1;
			}
			//handles the numerals in row 5
			else if(lowPlain[i] >= '0' && lowPlain[i] <= '3'){
				row = ceil(abs(lowPlain[i] + 2) / 10);
				col = ((abs(lowPlain[i] - 5)) % 10);
			}
			//handles row 6
			else if(lowPlain[i] >= '4' && lowPlain[i] <= '9'){
				row = ceil(abs(lowPlain[i] + 8) / 10);
				col = ((abs(lowPlain[i] - 1)) % 10);
			}
			ciphertext+=(to_string(row)+to_string(col)+" ");
		}
		//pass any symbols through
		else{
			unsupported = lowPlain[i];
			ciphertext+=(unsupported + " ");
		}
	}
	return (ciphertext);
}

string polybiusDecode(string ciphertext){
	

	return (ciphertext + " (DECODED)");
}

void polybiusAgain(){
	char choice;
	cout << "\nUse polybius again? [y/n]: " << flush;
	cin >> choice;
	if(choice == 'y'){
		polybius();
	}
	else if (choice == 'n'){
		//return to main menu
		exit(0);
	}
	else{
		cout << "Please enter y or n." << flush;
		polybiusAgain();
	}
}