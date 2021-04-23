// Jayden Campbell
//
// April 22, 2021

#include "StandardHFile.h"

class InvalidCharacterException{};
class InvalidRangeException{};
char character(char, int);

int main() {
	char c;
	int i;
	char newC;
	bool valid = false;
	while (!valid) {
		try {
			cout << "Please enter an alphabetical letter: ";
			cin >> c;
			get(i, "Please enter a number to offset the letter: ");
			newC = character(c, i);
			cout << c << " rotated " << i << " times is " << newC << ".\n";
			valid = true;
		}
		catch (InvalidCharacterException) {
			cout << "Invalid character entered. Please enter an alphabetical letter.\n";
		}
		catch (InvalidRangeException) {
			cout << "Range leads to invalid character. Please enter a valid number.\n";
		}
	}
	cin.ignore(100, '\n');
	leave();
}

char character(char start, int offset) {
	if (!isalpha(start)) {
		InvalidCharacterException invalidCharacterException;
		throw invalidCharacterException;
	}
	if (offset > 25) {
		InvalidRangeException invalidRangeException;
		throw invalidRangeException;
	}
	start += offset;
	if (!isalpha(start)) {
		InvalidRangeException invalidRangeException;
		throw invalidRangeException;
	}
	return start;
}
