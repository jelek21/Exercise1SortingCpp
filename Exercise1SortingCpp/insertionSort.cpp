#include "insertionSort.h"
#include "Output.h"



// Insertion Sort class 
std::pair<vector<int>, vector<int>> insertionSort::SortIntVector(vector<int> List)
{
	int  j;
	pair<int, int> k;
	int Listsize = List.size();


	//Creation of vector of pair used for keeping the indexes
	vector<pair<int,int>> Alt(Listsize);

	for (int i = 0; i < Listsize; i++)
	{
		Alt[i].first = List[i];
		Alt[i].second = i;
	}


	//Insertion sorting the vector 
	for (int i = 1; i < Listsize; i++)
	{
		j = i;
		k = Alt[i];

		while (j > 0 && k.first < Alt[j - 1].first)
		{
			Alt[j] = Alt[j - 1];
			j--;
		}
		Alt[j] = k;
	}


	//Creation of index vector
	vector<int> index(Listsize);

	for (int i = 0; i < Listsize; i++)
	{
		index[i] = Alt[i].second;
	}


	//Creation of list vector
	for (int i = 0; i < Listsize; i++)
	{
		List[i] = Alt[i].first;
	}


	//return of the two vectors 
	return { List, index };
}