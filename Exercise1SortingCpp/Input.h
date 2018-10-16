#include <iostream>
#include <vector>
using namespace std;

class Input{
public:
	/**
	* Normal public method that returns a vector of integers.
	* It returns a vector of n integers (n and the integers are asked to the user).
	* @parameter void, this function does not need any input.
	* @return vector<int> the vector of integer of length n (inputed by the user).
	*/
	static vector<int> AskIntVector();

private:
	static int InputInt(int A);
};
