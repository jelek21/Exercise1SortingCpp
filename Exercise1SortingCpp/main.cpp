#include <iostream>
#include <vector>

#include "Input.h"
#include "Output.h"
#include "insertionSort.h"

using namespace std;

int main(){
	vector <int> V;
	int a;
	V = Input::AskIntVector();
	vector<int> sorted = get<0>(insertionSort::SortIntVector(V));
	vector<int> indexes = get<1>(insertionSort::SortIntVector(V));
	a = Output::PrintString("The unsorted vector is: ", true);
	a = Output::PrintIntVector(V);
	a = Output::PrintString("The sorted vector is: ", true);
	a = Output::PrintIntVector(sorted);
	a = Output::PrintString("The indexes vector is: ", true);
	a = Output::PrintIntVector(indexes);
	a = Output::PrintString("", true);
	a = Output::PrintString("Please type any key to end", true);
	cin >> a;
}
