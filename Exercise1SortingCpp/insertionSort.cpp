#include "insertionSort.h"
#include "Output.h"



// Insertion Sort class 
std::pair<vector<int>, vector<int>> insertionSort::SortIntVector(vector<int> list)
{
	int  j;
	pair<int, int> k;
	int listsize = list.size();


	//Creation of vector of pair used for keeping the indexes
	vector<pair<int,int>> alt(listsize);

	for (int i = 0; i < listsize; i++)
	{
		alt[i].first = list[i];
		alt[i].second = i;
	}


	//Insertion sorting the vector 
	for (int i = 1; i < listsize; i++)
	{
		j = i;
		k = alt[i];

		while (j > 0 && k.first < alt[j - 1].first)
		{
			alt[j] = alt[j - 1];
			j--;
		}
		alt[j] = k;
	}


	//Creation of index vector
	vector<int> index(listsize);

	for (int i = 0; i < listsize; i++)
	{
		index[i] = alt[i].second;
	}


	//Creation of list vector
	for (int i = 0; i < listsize; i++)
	{
		list[i] = alt[i].first;
	}


	//return of the two vectors 
	return { list, index };
}