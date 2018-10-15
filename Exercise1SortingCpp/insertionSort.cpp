#include "insertionSort.h"




//Insertion Sort Algorithm
std::pair<vector<int>, vector<int>> insertionSort::SortIntVector(vector<int> list)
{
	int  j, k;
	vector<int> aux(list.size());

	for (int i = 1; i < list.size(); i++)
	{
		j = i;
		k = list[i];

		while (j > 0 && k < list[j - 1])
		{
			list[j] = list[j - 1];
			j--;
		}
		aux[i] = j;
		list[j] = k;
	}
	return { list, aux };
}