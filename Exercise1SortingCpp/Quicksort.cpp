#include "Quicksort.h"

vector<int> QuickSort::StartSorting(vector<int> V) {
	vector<int> W;
	W = V;
	QuickSorting(W, 0, W.size() - 1);
	return W;
}

void QuickSort::swap(vector<int> & V, int i, int j) {
	int tmp = V[i];
	V[i] = V[j];
	V[j] = tmp;
}

void QuickSort::QuickSorting(vector<int> & V, int low, int high) {
	if (low >= high) return;

	int p = Partition(V, low, high);

	QuickSort(V, low, p - 1);
	QuickSort(V, p + 1, high);

}

int QuickSort::Partition(vector<int> & V, int low, int high) {
	int p = low;
	for (int i = p + 1; i <= high; ++i) {
		if (V[i] < V[p]) {
			swap(V, i, p);
			if (i != p + 1) {
				swap(V, i, p + 1);
			}
			p = p + 1;
		}
	}
	return p;
}