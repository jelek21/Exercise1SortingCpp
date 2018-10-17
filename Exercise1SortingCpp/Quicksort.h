#include <iostream>
#include <vector>
using namespace std;

class QuickSort {
public:
	/**
	* Normal public method that returns a vector of int.
	* Launch the sorting algorithm.
	* @param A Vector of integer V.
	* @return  The vector of integers sorted.
	*/
	vector<int> StartSorting(vector<int> V);

private:
	/**
	* Normal private method that returns a vector.
	* Swaps the two elements V[i] and V[j] in the vector.
	* @param A Vector V, an int i (the index of the first element) an int j (the index of the second element).
	* @return  The vector with the two elements swapped.
	*/
	void Swapper(vector<int> & V, int i, int j);

	/**
	* Normal private method that execute the quicksort script.
	* Sort a vector of int.
	* @param A Vector V, an int low (the index of the first element) an int high (the index of the second element).
	* @return  The vector in sorting.
	*/
	void QuickSorting(vector<int> & V, int low, int high);

	/**
	* Normal public method that returns int (a status).
	* It prints an integer.
	* @param A String S, the string you want to print and a bool Eline (endl at the end of the print or not).
	* @return  An status in (0=OK !0=NOK).
	*/
	int Partitioner(vector<int> & V, int low, int high);
};