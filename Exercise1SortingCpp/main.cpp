#include <iostream>
#include <vector>

#include "Input.h"
#include "Output.h"
#include "insertionSort.h"
#include "Quicksort.h"
#include "TestPlan.h"

using namespace std;

int main(){
	TestPlan Test;
	vector<int> V;
	int a;
	V = Input::AskIntVector();
	vector<int> Sorted = get<0>(insertionSort::SortIntVector(V));
	vector<int> Indexes = get<1>(insertionSort::SortIntVector(V));
	Output o;

	if (Test.IsSorted(V)) cout << "True" << endl << endl;
	else cout << "False" << endl << endl;
	
	if (Test.IsSorted(Sorted)) cout << "True" << endl << endl;
	else cout << "False" << endl << endl;

	//Print of the vectors for Insertion Sort algorithm
	a = o.PrintString("The vector you entered is: ", true);
	a = o.PrintIntVector(V);
	a = o.PrintString("The vector sorted by the insdertion algorithm is: ", true);
	a = o.PrintIntVector(Sorted);
	a = o.PrintString("The indexes vector is: ", true);
	a = o.PrintIntVector(Indexes);
	a = o.PrintString("", true);


	//Print of the vector for Quick Sort algorithm
	QuickSort QSort;
	vector<int> W = QSort.StartSorting(V);
	a = o.PrintString("The vector sorted by the Quicksort algorithm is : ", true);
	a = o.PrintIntVector(W);
	

	//End 
	a = o.PrintString("Please type any key to end", true);
	cin >> a;
}