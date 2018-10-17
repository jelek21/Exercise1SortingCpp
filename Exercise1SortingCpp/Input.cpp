#include "Input.h"
#include "Output.h"

/* O is an object of the class Output ( Build to access all the output functions ) */
Output O;

std::vector<int> Input::AskIntVector()
{
	int Length = 0;
	int Integer = 0;
	O.PrintString("Please give the number of integer you want to enter ", true);
	Length = Input::InputInt();
	vector<int> returnTable(Length);
	O.PrintString("Please enter the ", false);
	O.PrintInt(Length, false);
	O.PrintString(" Integers", true);
	for (int i = 0; i < Length; i++) {
		O.PrintString("Integer ", false);
		O.PrintInt((i + 1), false);
		O.PrintString(" of ", false);
		O.PrintInt(Length, true);
		Integer = Input::InputInt();		
		returnTable[i] = Integer;
	}
	return returnTable;
}

int Input::InputInt() {
	int Integer = 0;
	while (!(cin >> Integer)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		O.PrintString("Invalid input.  Try again: ", true);
	}
	return Integer;
}