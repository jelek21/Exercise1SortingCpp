#include "TestPlan.h"
#include "Output.h"
#include "Input.h"

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
		A = rand() % ((Length + 1) / (2*RandomRatio));
		B = rand() % 2;
		if (B > 0) return -A;
		else return A;
	}
}

bool TestPlan::IsSorted(vector<int> V) {
	for (int i = 1; i < V.size(); i++) {
		if (V[i - 1] > V[i]) return false;
	}
	return true;
}

vector<int> TestPlan::TestLauncher()
{
	Input I;
	Output O;
	vector<int> V;
	O.PrintString("Please enter the Length of the vector", true);
	int Length = I.InputInt();
	O.PrintString("Please enter the ratio of random", true);
	int Ratio = I.InputInt();
	O.PrintString("Please enter 1 to activate negative numbers or 0 if you dont want negatives", true);
	int Neg = I.InputInt();

	if (Neg = 0) V = VectorCreator(Length, Ratio, false);
	else V = VectorCreator(Length, Ratio, true);
	
	return V;
}
