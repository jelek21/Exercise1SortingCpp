#ifndef _DIAGRAMS_OUTPUT_H
#define _DIAGRAMS_OUTPUT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
	* @param An int x, the integer you want to print and a bool Eline (endl at the end of the print or not).
	* @return  An int : status in (0=OK !0=NOK).
	*/
	int PrintInt(int x, bool Eline);

	/**
	* Normal public method that returns int (a status).
	* It prints the Insertio sort result.
	* @param The sorted vector<int> and the Indexes vector<int>
	* @return  An int : status in (0=OK !0=NOK).
	*/
	int PrintInsertResult(vector<int> Sorted, vector<int> Indexes);

	/**
	* Normal public method that returns int (a status).
	* It prints a double.
	* @param A double, the double you want to print and a bool Eline (endl at the end of the print or not).
	* @return  An int : status in (0=OK !0=NOK).
	*/
	int PrintDouble(double x, bool Eline);

	/**
	* Normal public method that returns int (a status).
	* It prints a the duration results.
	* @param Duratio (double), The duration you want to print and a Type (1 or 2 for Insertion sort or Quicksort).
	* @return  An int : status in (0=OK !0=NOK).
	*/
	int PrintDurationResult(double Duration, int Type);

	/**
	* Normal public method that returns int (a status).
	* write the results entered in the file file
	* @param A double, the double you want to print and a bool Eline (endl at the end of the print or not).
	* @return  An int : status in (0=OK !0=NOK).
	*/
	int ResultWrite(string file, int X, vector<double> Time);
};
#endif