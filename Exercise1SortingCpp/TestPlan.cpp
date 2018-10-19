#include "TestPlan.h"
#include "Output.h"
#include "Input.h"
#include "insertionSort.h"
#include "Quicksort.h"

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
	if (2 * RandomRatio > Length) RandomRatio = 1;
	if (!Negatives) {
		A = rand()%((int)floor((Length + 1)/RandomRatio));
		return A;
	}
	else {
		RandomRatio = 2 * RandomRatio;
		int P = (Length + 1) / RandomRatio;
		A = (int)floor(rand() % P);
		B = rand()%2;
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

void TestPlan::UltimeTest()
{
	Output O;
	O.PrintString("Your result files are in creation", true);
	string OF = "..\\Results.dat";
	int Ratio = 3;
	bool Neg = true;

	O.ResultWrite(OF, 2, PerformanceTest(2, Ratio, Neg));
	O.ResultWrite(OF, 5, PerformanceTest(5, Ratio, Neg));
	O.ResultWrite(OF, 10, PerformanceTest(10, Ratio, Neg));
	O.ResultWrite(OF, 50, PerformanceTest(50, Ratio, Neg));
	O.ResultWrite(OF, 100, PerformanceTest(100, Ratio, Neg));
	O.ResultWrite(OF, 250, PerformanceTest(250, Ratio, Neg));
	O.ResultWrite(OF, 500, PerformanceTest(500, Ratio, Neg));
	O.ResultWrite(OF, 1000, PerformanceTest(1000, Ratio, Neg));
	O.ResultWrite(OF, 2500, PerformanceTest(2500, Ratio, Neg));
	O.ResultWrite(OF, 5000, PerformanceTest(5000, Ratio, Neg));
	O.ResultWrite(OF, 10000, PerformanceTest(10000, Ratio, Neg));
	O.ResultWrite(OF, 25000, PerformanceTest(25000, Ratio, Neg));
	//O.ResultWrite(OF, 100000, PerformanceTest(100000, Ratio, Neg));
	//O.ResultWrite(OF, 1000000, PerformanceTest(1000000, Ratio, Neg));
}

vector<double> TestPlan::PerformanceTest(int Length, int Ratio, bool Neg) {
	Output O;
	QuickSort QSort;
	vector<int> V;
	vector<double> Ret(2);
	chrono::steady_clock::time_point tIS1 = chrono::steady_clock::now();
	chrono::steady_clock::time_point tIS2 = chrono::steady_clock::now();
	chrono::steady_clock::time_point tQS1 = chrono::steady_clock::now();
	chrono::steady_clock::time_point tQS2 = chrono::steady_clock::now();
	
	V = VectorCreator(Length, Ratio, Neg);
	
	tIS1 = chrono::steady_clock::now();
	vector<int> ISorted = get<0>(insertionSort::SortIntVector(V));
	tIS2 = chrono::steady_clock::now();
	chrono::duration<double> TimeSpanIS = chrono::duration_cast<chrono::duration<double>>(tIS2 - tIS1);
	Ret[0] = TimeSpanIS.count();
	if (IsSorted(ISorted)) {
		O.PrintString("Insertion sort successed on a vector ", false);
		O.PrintInt(Length, true);
		O.PrintString("", true);
	}
	else {
		O.PrintString("Insertion sort Failed on a vector ", false);
		O.PrintInt(Length, true);
		O.PrintString("", true);
	}
	
	tQS1 = chrono::steady_clock::now();
	vector<int> QSorted = QSort.StartSorting(V);
	tQS2 = chrono::steady_clock::now();
	chrono::duration<double> TimeSpanQS = chrono::duration_cast<chrono::duration<double>>(tQS2 - tQS1);
	Ret[1] = TimeSpanQS.count();
	if (IsSorted(QSorted)) {
		O.PrintString("Quicksort successed on a vector ", false);
		O.PrintInt(Length, true);
		O.PrintString("", true);
	} else {
		O.PrintString("Quicksort Failed on a vector ", false);
		O.PrintInt(Length, true);
		O.PrintString("", true);
	}
	V.~vector<int>();
	ISorted.~vector<int>();
	QSorted.~vector<int>();
	return Ret;
}
