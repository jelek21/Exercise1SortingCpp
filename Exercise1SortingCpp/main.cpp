#include <iostream>
#include <vector>

#include "Input.h"
#include "Output.h"
#include "insertionSort.h"
#include "Quicksort.h"

using namespace std;

int main(){

	vector<int> V;
	int a;
	V = Input::AskIntVector();
	vector<int> sorted = get<0>(insertionSort::SortIntVector(V));
	vector<int> indexes = get<1>(insertionSort::SortIntVector(V));
	Output o;


	//Print of the vectors for Insertion Sort algorithm
	a = o.PrintString("The vector you entered is: ", true);
	a = o.PrintIntVector(V);
	a = o.PrintString("The vector sorted by the insdertion algorithm is: ", true);
	a = o.PrintIntVector(sorted);
	a = o.PrintString("The indexes vector is: ", true);
	a = o.PrintIntVector(indexes);
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