#include "Output.h"

int Output::PrintIntVector(vector<int> V)
{
	for (unsigned __int64 i = 0; i < V.size(); i++) {
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

int Output::PrintInt(int x, bool Eline) {
	cout << x;
	if (Eline) cout << endl;
	return 0;
}