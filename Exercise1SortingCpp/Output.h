#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Output{
public:

	/**
	* Normal public method that returns int (a status).
	* It prints a vector of any number of integers (the length is computed inside the function).
	* @parameter vector<int> the vector of integer you want to print.
	* @return  An status in (0=OK !0=NOK).
	*/
	static int PrintIntVector(vector<int> V);

	/**
	* Normal public method that returns int (a status).
	* It prints a vector of any number of integers (the length is computed inside the function).
	* @parameter A String S, the string you want to print and a bool Eline (endl at the end of the print or not).
	* @return  An status in (0=OK !0=NOK).
	*/
	static int PrintString(string S, bool Eline);
};