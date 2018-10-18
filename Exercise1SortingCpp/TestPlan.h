#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>
#include <math.h>


using namespace std;

class TestPlan{
public:
	/**
	* Simple public method that chek if a vector is sorted.
	* @param V (vector<int>) : the vector you want to check;
	* @return boolean : true = the vector is sorted, false = the vector is not sorted.
	*/
	bool IsSorted(vector<int> V);

	/**
	* Simple public method that creates a random vector with parameters asked to the user :
	* The length, a randomratio (the average number of time you meet a number)
	* and with or without negative numbers.
	* @param void, everything is asked to the user
	* @return Vector<int> the vector randomly generated with the parameters inputed by the user.
	*/
	vector<int> TestLauncher();

	/**
	* Simple public method that test performances on many different vectors
	* @param void, everything is defined inside the method
	* @return void, it creates a file with results, the file is gnuplot ready.
	*/
	void UltimeTest();

private:
	/**
	* Simple private function that will generate a random int with the parameters inputed:
	* The Ratio and the Length of the vector ( in fact it will create a range )
	* the boolean Negatives which activate or not a random negatives generator
	* @param RandomRatio (int) : the ratio, Length (int) the length of the vector, Negatives (bool) true = negatives on/fales = negatives off
	* @return int the random int generated.
	*/
	int RandomInt(int RandomRatio, int Length, bool Negatives);\

	/**
	* Simple private method that creates a random vector of the length inputed
	* with a randomratio (the average number of time you meet a number)
	* and with or without negative numbers.
	* @param Length (int) : the length of the vector, RandomRatio (int) : the Ratio, Negatives (bool) activate or no the negative numbers.
	* @return Vector<int> the vector randomly generated with the above parameters.
	*/
	vector<int> VectorCreator(int Length, int RandomRatio, bool Negatives);

	/**
	* Simple private method that compute the performance test automatically on Quicksort
	* it returns the time result
	* @param Length (int) : the length of the vector.
	* @return double: the time spend to sort.
	*/
	double PerformanceQSTest(int Length, int Ratio, bool Neg);

	/**
	* Simple private method that compute the performance test automatically on Insertion Sort
	* it returns the time result
	* @param Length (int) : the length of the vector.
	* @return double: the time spend to sort.
	*/
	double PerformanceISTest(int Length, int Ratio, bool Neg);
};


