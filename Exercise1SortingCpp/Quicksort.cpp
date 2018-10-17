#include "Quicksort.h"

void QuickSort::Swapper(vector<int> & V, int i, int j) {
	int Tmp = V[i];
	V[i] = V[j];
	V[j] = Tmp;
}

void QuickSort::QuickSorting(vector<int> & V, int Low, int High) {
	if (Low >= High) return;

	int Partition = Partitioner(V, Low, High);

	QuickSorting(V, Low, Partition - 1);
	QuickSorting(V, Partition + 1, High);

}

int QuickSort::Partitioner(vector<int> & V, int Low, int High) {
	int Pivot = Low;
	for (int i = Pivot + 1; i <= High; ++i) {
		if (V[i] < V[Pivot]) {
			Swapper(V, i, Pivot);
			if (i != Pivot + 1) {
				Swapper(V, i, Pivot + 1);
			}
			Pivot = Pivot + 1;
		}
	}
	return Pivot;
}

vector<int> QuickSort::StartSorting(vector<int> V) {
	static vector<int> W;
	W = V;
	int size = W.size() - 1;
	QuickSorting(W, 0, size);
	return W;
}