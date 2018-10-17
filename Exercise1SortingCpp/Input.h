#include <iostream>
#include <vector>
#include<limits>

using namespace std;

class Input{
public:
	/**
	* Normal public method that returns a vector of integers.
	* It returns a vector of n integers (n and the integers are asked to the user).
	* @param void, this function does not need any input.
	* @return vector<int> the vector of integer of length n (inputed by the user).
	*/
	static vector<int> AskIntVector();

	/**
	* Normal public method that returns an integer.
	* It returns an integer asked to the user.
	* @param void, this function does not need any input.
	* @return int the integer input by the user integer.
	*/
	static int InputInt();
};
