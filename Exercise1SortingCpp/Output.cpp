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

int Output::PrintInsertResult(vector<int> Sorted, vector<int> Indexes) {
	int a = PrintString("The vector sorted by the insertion algorithm is: ", true);
	a = PrintIntVector(Sorted);
	a = PrintString("The indexes vector is: ", true);
	a = PrintIntVector(Indexes);
	a = PrintString("", true);
	return a;
}

int Output::PrintDouble(double x, bool Eline)
{
	cout << x;
	if (Eline) cout << endl;
	return 0;
}

int Output::PrintDurationResult(double Duration, int Type)
{
	int a;
	if (Type == 1) a = PrintString("The time spent to sort via Insertion sort algorithm is:", true);
	else  a = PrintString("The time spent to sort via Quicksort algorithm is:", true);
	a = PrintDouble(Duration, false);
	a = PrintString(" s", true);
	a = PrintString("", true);
	return 0;
}

int Output::ResultWrite(string file, int X, double Time) {
	ofstream f;
	f.open(file, std::ios_base::app);
	f << X << "    ";
	f << Time << endl;
	f.close();
	return 0;
}