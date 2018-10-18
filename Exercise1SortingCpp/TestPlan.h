#include <vector>
#include <chrono>
#include <iostream>

using namespace std;

class TestPlan{
public:
	/**
	*
	*
	*
	*
	*/
	vector<int> VectorCreator(int Length, int RandomRatio, bool Negatives);

	bool IsSorted(vector<int> V);

private:
	/**
	*
	*
	*
	*
	*/
	int RandomInt(int RandomRatio, int Length, bool Negatives);

};


