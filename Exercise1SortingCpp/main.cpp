#ifndef _DIAGRAMS_main_H
#define _DIAGRAMS_main_H
#include <iostream>
#include <vector>
#include <chrono>

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
	QuickSort QSort;
	
	chrono::steady_clock::time_point tIS1 = chrono::steady_clock::now();
	chrono::steady_clock::time_point tIS2 = chrono::steady_clock::now();
	chrono::steady_clock::time_point tQS1 = chrono::steady_clock::now();
	chrono::steady_clock::time_point tQS2 = chrono::steady_clock::now();


	int a;
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	int Z = I.Startup();
	// If the user asked to enter a vector
	if (Z == 1) V = I.AskIntVector();
	// If the user asked to generate a random vector
	else if (Z==2) V = Test.TestLauncher();
	else {
		Test.UltimeTest();
		return 0;
	}
	
	// Sort the vector V with Insertion sort method
	tIS1 = chrono::steady_clock::now();
	vector<int> Sorted = get<0>(insertionSort::SortIntVector(V));
	tIS2 = chrono::steady_clock::now();
	chrono::duration<double> TimeSpanIS = chrono::duration_cast<chrono::duration<double>>(tIS2 - tIS1);
	vector<int> Indexes = get<1>(insertionSort::SortIntVector(V));

	// Sort the vector V with Quicksort method
	tQS1 = chrono::steady_clock::now();
	vector<int> W = QSort.StartSorting(V);
	tQS2 = chrono::steady_clock::now();
	chrono::duration<double> TimeSpanQS = chrono::duration_cast<chrono::duration<double>>(tQS2 - tQS1);

	//Print of the vectors for Insertion Sort algorithm
	a = O.PrintString("The vector you entered is: ", true);
	a = O.PrintIntVector(V);
	a = O.PrintInsertResult(Sorted, Indexes);

	//Print of the vector for Quick Sort algorithm
	a = O.PrintString("The vector sorted by the Quicksort algorithm is : ", true);
	a = O.PrintIntVector(W);
	
	//Print time results
	a = O.PrintDurationResult(TimeSpanIS.count(), 1);
	a = O.PrintDurationResult(TimeSpanQS.count(), 2);

	//End 
	a = O.PrintString("Please type any key to end", true);
	int b;
	cin >> b;
	return a;
}
#endif