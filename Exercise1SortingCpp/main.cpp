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
	Output O;
	Input I;
	vector<int> V;
	int a;
	int Z = I.Startup();
	if (Z == 1) V = I.AskIntVector();
	else V = Test.TestLauncher();
	
	vector<int> Sorted = get<0>(insertionSort::SortIntVector(V));
	vector<int> Indexes = get<1>(insertionSort::SortIntVector(V));

	//Print of the vectors for Insertion Sort algorithm
	a = O.PrintString("The vector you entered is: ", true);
	a = O.PrintIntVector(V);
	a = O.PrintString("The vector sorted by the insertion algorithm is: ", true);
	a = O.PrintIntVector(Sorted);
	a = O.PrintString("The indexes vector is: ", true);
	a = O.PrintIntVector(Indexes);
	a = O.PrintString("", true);

	//Print of the vector for Quick Sort algorithm
	QuickSort QSort;
	vector<int> W = QSort.StartSorting(V);
	a = O.PrintString("The vector sorted by the Quicksort algorithm is : ", true);
	a = O.PrintIntVector(W);
	

	//End 
	a = O.PrintString("Please type any key to end", true);
	cin >> a;
}