#include "Input.h"
#include "Output.h"

std::vector<int> Input::AskIntVector()
{
	int length = 0;
	int Integer;
	Output::PrintString("Please enter the length of the array you want to create", true);
	length = Input::InputInt(length);
	vector<int> returnTable(length);
	cout << "Please enter the " << length << "Integers" << endl;
	for (int i = 0; i < length; i++) {
		cout << "Integer " << i+1 << " of " << length << endl;
		cin >> Integer;
		returnTable[i] = Integer;
	}
	return returnTable;
}

int Input::InputInt(int A) {
	cin >> A;
	return A;
}