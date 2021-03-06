// interviewPracticeStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TO DO
// Check UpperCase and LoweCase converters
// Check how to add the NULL to 1.2
// Check how to use getline after a cin in 1.3
// Check when do a and A start, same with special characters
// Check atoi usage


// 1.1 Check if string has all unique characters (no aditionnal data structures)
// Assume it will not have numbers nor special characters (nor spaces)
// Asume uppercases and lower cases are the same
bool checkUniqueness(string s) {
	char bufferChar;
	int cont = 0;
	while (cont < s.size() - 1) {
		bufferChar = s[cont];
		for (int i = cont + 1; i < s.size(); ++i) {
			if (bufferChar == s[i]) {
				return false;
			}
		}

		cont++;
	}

	return true;
}

// 1.2 Reverse a C-Style String, including the null character
// Verify with strings of length even and odd!
void reverseString(string& s) {
	char aux;
	int end = s.size() - 1;
	for (int start = 0; start < end; ++start) {
		aux = s[start];
		s[start] = s[end];
		s[end] = aux;
		end--;
	}

}

// 1.3 Remove Duplicate from string (no additional buffer)
void locateDuplicates(string& s) {
	char buffer;
	int checked = 0;
	// No need to compare the last char, as the others have already been compared to it
	while (checked < s.size() - 1) {
		buffer = s[checked];
		// To make it more efficient, no / will be checked as we know this character can not be an input (it can only be inserted by us and it means that that char has already been checked)
		if (buffer != '/') {
			for (int i = checked + 1; i < s.size(); ++i) {
				if (s[i] == buffer) {
					s[i] = '/';
				}
			}
		}
		++checked;
	}

}

void eliminateDuplicates(string& s) {
	locateDuplicates(s);

	// Be careful when eliminating as it can displace the chars 
	// Start at 1 because s[1] will never be a duplicated char
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == '/') {
			s.erase(i, 1);
			--i;
		}
	}

	cout << s << endl;
}

// 1.4 Check if 2 strings are anagrams
// Do not consider special characters
// Assume that there will not be UpperCase Letters (otherwise you have to convert them all to the same standard, either Up or Down case)
bool areTheyAnagrams(string s1, string s2) {

	// There are 26 letters in the English Alphabet
	vector<int> alphabetS1;
	vector<int> alphabetS2;
	// Initialize values at 0;
	for (int i = 0; i < 26; ++i) {
		alphabetS1.push_back(0);
		alphabetS2.push_back(0);
	}

	// First, iterate through the string, and depending on what it finds, update the vector[i] by + 1
	// a is 97 in ASCII so we substract that amount to what it finds to update the appropiate i
	for (int i = 0; i < s1.size(); ++i) {
		alphabetS1[s1[i] - 97] += 1;
	}

	for (int i = 0; i < s2.size(); ++i) {
		alphabetS2[s2[i] - 97] += 1;
	}

	for (int i = 0; i < 26; ++i) {
		cout << alphabetS1[i] << " " << alphabetS2[i] << endl;
		if (alphabetS1[i] != alphabetS2[i]) {
			return false;
		}
	}

	return true;
}

// 1.7 If an element in an MxN matrix is 0, its entire row and column is set to 0
class Token {
private:
	int x, y;
public:
	int getX() { return this->x; }
	int getY() { return this->y; }
	Token() { x = 0; y = 0; }
	Token(int x, int y) { this->x = x; this->y = y; }
};

// This method with only work for j = 4 and i = 3 because it is a array of arrays, to make it variable you might want to use vectors instead (or you could manually change j and i every time)
void rowAndColumnToZero(int matrix[4][3]) {
	vector<Token>container;

	// First locate all of the 0s and push them to the container
	// If you edit without this step you will end up with a matriz full of 0s as you would correct 0s just added
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 3; ++i) {
			if (matrix[j][i] == 0) {
				Token has0(i, j);
				container.push_back(has0);
			}
		}
	}

	// Now that you have all the original 0s, iterate through them and change the whole row and column they are at

	int currInContainer = 0;
	while (currInContainer < container.size()) {
		int changeX = container[currInContainer].getX(), changeY = container[currInContainer].getY();
		
		for (int j = 0; j < 4; ++j) {
			matrix[j][changeX] = 0;
		}

		for (int i = 0; i < 3; ++i) {
			matrix[changeY][i] = 0;
		}
		++currInContainer;
	}

}

int main(){

	char op;


	do {
		cout << "ENTRE e TO END" << endl;
		cin >> op;
		cout << "AFTER" << endl;
		

	} while (op != 'e');

}

