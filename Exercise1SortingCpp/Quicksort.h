#include <iostream>
#include <vector>
using namespace std;

class QuickSort {
public:
	static vector<int> StartSorting(vector<int> V);

private:
	void swap(vector<int> & V, int i, int j);
	void QuickSorting(vector<int> & V, int low, int high);
	int Partition(vector<int> & V, int low, int high);
};