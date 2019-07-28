/**
 * Author:		Joe Dunton
 * File:		cipherize.cpp
 * Desc:		This is the main code for cipherize
**/


//includes
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <cstdlib>

//using decs
using std::cin;
using std::cout;
using std::ifstream;
using std::endl;
using std::flush;
using std::string;

//func protos
void printTitle();
void printMenu();
void polybius();


int main (int argc, char *argv[]) {
	system ("clear && tput civis"); 
	int select;
	printTitle();
	printMenu();
	system ("tput sgr0 && tput civis");
	cin >> select;
	switch (select){
		case 1: 
			polybius();
			break;
		case 2:
			cout << "case 2" << endl;
			break;
		case 3:
			cout << "case 3" << endl;
			break;
		case 4:
			cout << "\n\nGoodbye!" << endl;
			exit(0);
	}
} 


void printTitle(){
	ifstream titleFile;
	titleFile.open("title.txt");
	if(titleFile.fail())
	{
		exit(1);
	}
	system ("tput setaf $((1 + RANDOM % 10)) && tput rev && tput bold");
	cout << titleFile.rdbuf();
	titleFile.close();
	system ("tput sgr0");
}

void printMenu(){
	system ("tput setaf 5");
	cout << "\n\nSelect option and press enter: " << endl;
	system ("tput setaf 1");
	cout << "1) Polybius Square" << endl;
	system ("tput setaf 2");
	cout << "2) Caesar Cipher" << endl;
	system ("tput setaf 3");
	cout << "3) Rot13" << endl;
	system ("tput setaf 4");
	cout << "4) exit" << endl;
	system ("tput sgr0");
	cout << "\n\n>> " << flush;
}
