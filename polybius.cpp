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
#include <bits/stdc++.h>
#include <vector>

//local includes
#include "cipherize.h"

//using decs
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::string;
using std::abs;
using std::to_string;
using std::istringstream;
using std::stoi;
using std::istream_iterator;
using std::vector;
using std::ifstream;

//func protos
string polybiusEncode(string plaintext);
string polybiusDecode(string ciphertext);
void polybiusAgain();
void polybiusHelp();

void polybius(){
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
			cout << "\nDecoded ciphertext is: " << polybiusDecode(input) << endl;
			system ("tput sgr0 && tput civis");
			break;
		case 2:
			cout << "Enter plaintext to encode: " << flush;
			cin >> input;
			cout << "\nEncoded plaintext is: " << flush;
			system ("tput setaf 2");
			cout << polybiusEncode(input) << endl;
			system ("tput sgr0 && tput civis");
			break;
		case 3:
			cipherHelp("polybius");
			break;
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
	string square[6][6] = {
		{"a", "b", "c", "d", "e", "f"},
		{"g", "h", "i", "j", "k", "l"},
		{"m", "n", "o", "p", "q", "r"},
		{"s", "t", "u", "v", "w", "x"},
		{"y", "z", "0", "1", "2", "3"},
		{"4", "5", "6", "7", "8", "9"}
	};
	string cipherLetter = "";
	string plaintext = "";
	string row;
	string col;

    vector<string> cipherLetters;
    istringstream iss(ciphertext);
    for(string s; iss >> s; )
        cipherLetters.push_back(s);

	for(int i=0; i < cipherLetters.size(); i++)
	{
		cipherLetter = cipherLetters[i];
		if(isdigit(cipherLetter[0])){
			col = cipherLetter[0];
			row = cipherLetter[1];
			plaintext+=square[stoi(col) - 1][stoi(row) - 1];
		}
		else{
			plaintext+=cipherLetter;
		}
	}
	return (plaintext);
}

void polybiusAgain(){
	char choice;
	cout << "\nUse polybius again? [" << flush;
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
		polybius();
	}
	else if (choice == 'n'){
		cipherize();
	}
	else{
		cout << "Please enter y or n." << flush;
		polybiusAgain();
	}
}
