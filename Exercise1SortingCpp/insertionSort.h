#ifndef _DIAGRAMS_InsertionSort_H
#define _DIAGRAMS_InsertionSort_H
#include <iostream>
#include <vector>

using namespace std;

class insertionSort {
public:
	/**
	* Normal public method that sorts a vector of integers.
	* It returns two vectors : the sorted vector and the vector containing the old indexes of the sorted vector.
	* @param vector<int> the vector of integer you want to sort.
	* @return a pair of vector<int> : sorted vector <1> and indexes vector <2>.
	*/
	static std::pair<vector<int>, vector<int>> SortIntVector(vector<int> list);
};
#endif