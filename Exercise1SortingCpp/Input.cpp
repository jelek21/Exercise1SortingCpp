#include "Input.h"

std::vector<int> Input::AskIntVector()
{
	int length;
	int Integer;
	cout << "Please enter the length of the array you want to create" << endl;
	cin >> length;
	vector<int> returnTable(length);
	cout << "Please enter the " << length << "Integers" << endl;
	for (int i = 0; i < length; i++) {
		cout << "Integer " << i+1 << " of " << length;
		cin >> Integer;
		returnTable[i] = Integer;
	}
	return returnTable;
}
