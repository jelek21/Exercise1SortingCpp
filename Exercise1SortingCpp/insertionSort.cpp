#include "insertionSort.h

//Insertion Sort Algorithm
std::pair<vector<int>, vector<int>> insertionSort::SortIntVector(vector<int> list)
{
	int  j, k;
	int listsize = list.size();
	vector<int> aux(listsize);
	
	for (int i = 1; i < listsize; i++)
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