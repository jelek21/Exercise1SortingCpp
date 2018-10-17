#include "TestPlan.h"

vector<int> TestPlan::VectorCreator(int Length, int RandomRatio, bool Negatives) {
	vector<int> V(Length);
	for (int i = 0; i < Length; i++) {
		V[i] = RandomInt(RandomRatio,Length,Negatives);
	}
	return V;
}

int TestPlan::RandomInt(int RandomRatio,int Length, bool Negatives) {
	int A;
	int B; 
	if (!Negatives) {
		A = rand() % ((Length + 1)/RandomRatio);
		return A;
	}
	else {
		A = rand() % ((Length + 1) / RandomRatio);
		B = rand() % 2;
		if (B > 0) return -A;
		else return A;
	}
}