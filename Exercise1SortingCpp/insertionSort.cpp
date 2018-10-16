#include "insertionSort.h"
#include "Output.h"

/* Insertion Sort Algorithm  */
std::pair<vector<int>, vector<int>> insertionSort::SortIntVector(vector<int> list)
{
	int  j, k;
	int listsize = list.size();
	vector<int> index(listsize);
	index[0] = 0;
	
	for (int i = 1; i < listsize; i++)
	{

		j = i;
		k = list[i];
		index[i] = i;

		while (j > 0 && k < list[j - 1])
		{
			list[j] = list[j - 1];
			index[j] = j - 1;
			j--;

		}
		index[j] = i;

		list[j] = k;
	}
	return { list, index };
}