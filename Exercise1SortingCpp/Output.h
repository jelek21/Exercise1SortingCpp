#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Output{
public:

	/**
	* Normal public method that returns int (a status).
	* It prints a vector of any number of integers (the length is computed inside the function).
	* @param vector<int> the vector of integer you want to print.
	* @return  An status in (0=OK !0=NOK).
	*/
	int PrintIntVector(vector<int> V);

	/**
	* Normal public method that returns int (a status).
	* It prints a vector of any number of integers (the length is computed inside the function).
	* @param A String S, the string you want to print and a bool Eline (endl at the end of the print or not).
	* @return  An int : status in (0=OK !0=NOK).
	*/
	int PrintString(string S, bool Eline);

	/**
	* Normal public method that returns int (a status).
	* It prints an integer.
	* @param A String S, the string you want to print and a bool Eline (endl at the end of the print or not).
	* @return  An int : status in (0=OK !0=NOK).
	*/
	int PrintInt(int x, bool Eline);
};