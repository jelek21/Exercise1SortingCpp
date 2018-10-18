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
	string QS = "..\\QS_Results.dat";
	string IS = "..\\IS_Results.dat";
	int Ratio = 3;
	bool Neg = true;
	O.ResultWrite(QS, 2 ,PerformanceQSTest(2, Ratio, Neg));
	O.ResultWrite(QS, 5, PerformanceQSTest(5, Ratio, Neg));
	O.ResultWrite(QS, 10, PerformanceQSTest(10, Ratio, Neg));
	O.ResultWrite(QS, 50, PerformanceQSTest(50, Ratio, Neg));
	O.ResultWrite(QS, 100, PerformanceQSTest(100, Ratio, Neg));
	O.ResultWrite(QS, 500, PerformanceQSTest(500, Ratio, Neg));
	O.ResultWrite(QS, 1000, PerformanceQSTest(1000, Ratio, Neg));
	O.ResultWrite(QS, 5000, PerformanceQSTest(5000, Ratio, Neg));
	O.ResultWrite(QS, 10000, PerformanceQSTest(10000, Ratio, Neg));
	

	O.ResultWrite(IS, 2, PerformanceISTest(2, Ratio, Neg));
	O.ResultWrite(IS, 5, PerformanceISTest(5, Ratio, Neg));
	O.ResultWrite(IS, 10, PerformanceISTest(10, Ratio, Neg));
	O.ResultWrite(IS, 50, PerformanceISTest(50, Ratio, Neg));
	O.ResultWrite(IS, 100, PerformanceISTest(100, Ratio, Neg));
	O.ResultWrite(IS, 500, PerformanceISTest(500, Ratio, Neg));
	O.ResultWrite(IS, 1000, PerformanceISTest(1000, Ratio, Neg));
	O.ResultWrite(IS, 5000, PerformanceISTest(5000, Ratio, Neg));
	O.ResultWrite(IS, 10000, PerformanceISTest(10000, Ratio, Neg));
	O.ResultWrite(IS, 100000, PerformanceISTest(100000, Ratio, Neg));
}

double TestPlan::PerformanceQSTest(int Length, int Ratio, bool Neg) {
	Output O;
	vector<int> V;
	chrono::steady_clock::time_point tIS1 = chrono::steady_clock::now();
	chrono::steady_clock::time_point tIS2 = chrono::steady_clock::now();
	V = VectorCreator(Length, Ratio, Neg);
	O.PrintIntVector(V);
	tIS1 = chrono::steady_clock::now();
	vector<int> Sorted = get<0>(insertionSort::SortIntVector(V));
	tIS2 = chrono::steady_clock::now();
	chrono::duration<double> TimeSpanIS = chrono::duration_cast<chrono::duration<double>>(tIS2 - tIS1);
	return TimeSpanIS.count();
}

double TestPlan::PerformanceISTest(int Length, int Ratio, bool Neg) {
	QuickSort QSort;
	vector<int> V;
	chrono::steady_clock::time_point tQS1 = chrono::steady_clock::now();
	chrono::steady_clock::time_point tQS2 = chrono::steady_clock::now();
	V = VectorCreator(Length, Ratio, Neg);
	tQS1 = chrono::steady_clock::now();
	vector<int> Sorted = QSort.StartSorting(V);
	tQS2 = chrono::steady_clock::now();
	chrono::duration<double> TimeSpanQS = chrono::duration_cast<chrono::duration<double>>(tQS2 - tQS1);
	return TimeSpanQS.count();
}