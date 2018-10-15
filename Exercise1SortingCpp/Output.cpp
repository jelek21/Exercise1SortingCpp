#include "Output.h"


int Output::PrintIntVector(vector<int> V)
{
	int Vsize = V.size();
	for (int i = 0; i < Vsize; i++) {
		cout << V[i] << "    ";
	}
	cout << endl;
	return 0;
}

int Output::PrintString(string S, bool Eline)
{
	cout << S;
	if (Eline) cout << endl;
	return 0;
}
