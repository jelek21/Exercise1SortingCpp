#include "Input.h"
#include "Output.h"

Output O;

std::vector<int> Input::AskIntVector()
{
	int length = 0;
	int Integer = 0;
	O.PrintString("Please give the number of integer you want to enter ", true);
	length = Input::InputInt();
	vector<int> returnTable(length);
	O.PrintString("Please enter the ", false);
	O.PrintInt(length, false);
	O.PrintString(" Integers", true);
	for (int i = 0; i < length; i++) {
		O.PrintString("Integer ", false);
		O.PrintInt((i + 1), false);
		O.PrintString(" of ", false);
		O.PrintInt(length, true);
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