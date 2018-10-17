#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <string>
#include <sstream>
#include <chrono>
#include <stdlib.h>


using namespace std;

int* createRandomArray(int sizeOfArrayA) {

	int *A = new int[sizeOfArrayA];

	int intSign = 0;
	for (int i(0); i < sizeOfArrayA; i++) {
		intSign = rand();
		if (intSign < (RAND_MAX*0.5)) {
			intSign = -1;
		}
		else {
			intSign = 1;
		}

		A[i] = rand() * intSign;

	}
	return A;
}

/*
* arrayBegin take as an entry the size of an integer array and ask the user
* to enter the value in order to return the int array
*/
int* arrayBegin(int& sizeOfArrayA)
{

	string line1, line2, lineChoice;
	int d;
	int choice;
	bool kek2;
	bool kek = false;
	cout << "What is the size of the array ?" << endl;
	//cin >> sizeOfArrayA;
	while (kek == false) {
		cin.clear();

		while (getline(cin, line1)) // This while loop enables to reject every value that is not an integer
		{
			stringstream ss1(line1);
			if (ss1 >> sizeOfArrayA)
			{
				if (ss1.eof())
				{   // Success
					break;
				}
			}
			cout << "Error! Please enter an integer, try again" << endl;
		}
		if (sizeOfArrayA < 0) {
			cout << "It's not a positiv integer, try again :" << endl;
		}
		else {
			kek = true;
		}
	}

	cout << "Do you wanna enter the values (1) or you could let us create a random array (0) " << endl;

	while (getline(cin, lineChoice)) // This while loop enables to reject every value that is not 0 or 1
	{
		stringstream ssChoice(lineChoice);
		if (ssChoice >> kek2)
		{
			if (ssChoice.eof())
			{   // Success
				choice = kek2;
				break;
			}
		}
		cout << "Error! Please enter 0 or 1, try again" << endl;
	}

	int *A = new int[sizeOfArrayA];

	if (choice == true) {



		cout << "Let's enter the values :" << endl;



		for (int j = 0; j < sizeOfArrayA; j++)
		{
			cout << "Element number " << j << " =";
			cin.clear();

			/*		if (j == 0) // Do the cin.ignore only for the first element to enter
					{
						cin.ignore(1000, '\n');
					}*/

			while (getline(cin, line2)) // This while loop enables to reject every value that is not an integer
			{
				stringstream ss2(line2);
				if (ss2 >> d)
				{
					if (ss2.eof())
					{   // Success
						break;
					}
				}
				cout << "Error! Please enter an integer, try again" << endl;
			}

			A[j] = d;
			cout << endl;
		}

		cout << "The Filling of the Array to sort is over" << endl;


	}
	else {
		A = createRandomArray(sizeOfArrayA);
	}

	return A;
}

int* arrayBeginPosition(int sizeOfArrayA) {

	int *A = new int[sizeOfArrayA];
	for (int j = 0; j < sizeOfArrayA; j++)
	{
		A[j] = j;

	}

	return A;
}

void insertionSortPosition(int tab[], int tabPosition[], int nbpoint) {
	int keyPoint = 0;
	int keyPointPosition = 0;

	int j;
	for (int i(1); i < nbpoint; i++) {
		keyPoint = tab[i];
		keyPointPosition = tabPosition[i];
		j = i - 1;
		while ((tab[j] > keyPoint) && (j >= 0)) {

			tab[j + 1] = tab[j];
			tabPosition[j + 1] = tabPosition[j];
			j = j - 1;

		}
		tab[j + 1] = keyPoint;
		tabPosition[j + 1] = keyPointPosition;
	}

}

/* Helper function for finding the max of two numbers */
int max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

/* left is the index of the leftmost element of the subarray; right is one
* past the index of the rightmost element */
void merge_helperPosition(int *input, int left, int right, int *scratch, int *inputPosition, int *scratchPosition)
{
	/* base case: one element */
	if (right == left + 1)
	{
		return;
	}
	else
	{
		int i = 0;
		int length = right - left;
		int midpoint_distance = length / 2;
		/* l and r are to the positions in the left and right subarrays */
		int l = left, r = left + midpoint_distance;

		/* sort each subarray */
		merge_helperPosition(input, left, left + midpoint_distance, scratch, inputPosition, scratchPosition);
		merge_helperPosition(input, left + midpoint_distance, right, scratch, inputPosition, scratchPosition);

		/* merge the arrays together using scratch for temporary storage */
		for (i = 0; i < length; i++)
		{
			/* Check to see if any elements remain in the left array; if so,
			* we check if there are any elements left in the right array; if
			* so, we compare them.  Otherwise, we know that the merge must
			* use take the element from the left array */
			if (l < left + midpoint_distance &&
				(r == right || max(input[l], input[r]) == input[l]))
			{
				scratch[i] = input[l];
				scratchPosition[i] = inputPosition[l];
				l++;
			}
			else
			{
				scratch[i] = input[r];
				scratchPosition[i] = inputPosition[r];
				r++;
			}
		}
		/* Copy the sorted subarray back to the input */
		for (i = left; i < right; i++)
		{
			input[i] = scratch[i - left];
			inputPosition[i] = scratchPosition[i - left];
		}
	}
}

/* mergesort returns true on success.  Note that in C++, you could also
* replace malloc with new and if memory allocation fails, an exception will
* be thrown.  If we don't allocate a scratch array here, what happens?
*
* Elements are sorted in reverse order -- greatest to least */

int mergesortPosition(int *input, int *inputPosition, int size)
{
	int *scratch = (int *)malloc(size * sizeof(int));
	int *scratchPosition = (int *)malloc(size * sizeof(int));
	if (scratch != NULL)
	{
		merge_helperPosition(input, 0, size, scratch, inputPosition, scratchPosition);
		free(scratch);
		return 1;
	}
	else
	{
		return 0;
	}
}

//***********************************************************************************************************
void merge_helper(int *input, int left, int right, int *scratch)
{
	/* base case: one element */
	if (right == left + 1)
	{
		return;
	}
	else
	{
		int i = 0;
		int length = right - left;
		int midpoint_distance = length / 2;
		/* l and r are to the positions in the left and right subarrays */
		int l = left, r = left + midpoint_distance;

		/* sort each subarray */
		merge_helper(input, left, left + midpoint_distance, scratch);
		merge_helper(input, left + midpoint_distance, right, scratch);

		/* merge the arrays together using scratch for temporary storage */
		for (i = 0; i < length; i++)
		{
			/* Check to see if any elements remain in the left array; if so,
			* we check if there are any elements left in the right array; if
			* so, we compare them.  Otherwise, we know that the merge must
			* use take the element from the left array */
			if (l < left + midpoint_distance &&
				(r == right || max(input[l], input[r]) == input[l]))
			{
				scratch[i] = input[l];
				l++;
			}
			else
			{
				scratch[i] = input[r];
				r++;
			}
		}
		/* Copy the sorted subarray back to the input */
		for (i = left; i < right; i++)
		{
			input[i] = scratch[i - left];
		}
	}
}

/* mergesort returns true on success.  Note that in C++, you could also
* replace malloc with new and if memory allocation fails, an exception will
* be thrown.  If we don't allocate a scratch array here, what happens?
*
* Elements are sorted in reverse order -- greatest to least */

int mergesort(int *input, int size)
{
	int *scratch = (int *)malloc(size * sizeof(int));
	if (scratch != NULL)
	{
		merge_helper(input, 0, size, scratch);
		free(scratch);
		return 1;
	}
	else
	{
		return 0;
	}
}
void insertionSort(int tab[], int nbpoint) {
	int keyPoint = 0;

	int j;
	for (int i(1); i < nbpoint; i++) {
		keyPoint = tab[i];
		j = i - 1;
		while ((tab[j] > keyPoint) && (j >= 0)) {

			tab[j + 1] = tab[j];
			j = j - 1;

		}
		tab[j + 1] = keyPoint;
	}

}

//***********************************************************************************************************
//TEST FUNCTION
/*
*Choice 1 : Classic insert
*Choice 2 : Insert + Index
*Choice 3 : Classic Merge
*Choice 4 : Merge + index
*/
double performanceDurationTest(int choice, int sizeofArray) {
	string label;
	int* A1 = createRandomArray(sizeofArray);
	int* A2 = createRandomArray(sizeofArray);
	int* Aposition2 = arrayBeginPosition(sizeofArray);
	int* A3 = createRandomArray(sizeofArray);
	int* A4 = createRandomArray(sizeofArray);
	int* Aposition4 = arrayBeginPosition(sizeofArray);


	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	switch (choice)
	{
	case 1:
		cout << "Classic insert with a random array[" << sizeofArray << "]" << endl;

		t1 = chrono::steady_clock::now();
		insertionSort(A1, sizeofArray);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);




		break;
	case 2:
		cout << "Insert + Index with a random array[" << sizeofArray << "]" << endl;


		t1 = chrono::steady_clock::now();
		insertionSortPosition(A1, Aposition2, sizeofArray);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);





		break;
	case 3:
		cout << "Classic merge with a random array[" << sizeofArray << "]" << endl;



		t1 = chrono::steady_clock::now();
		mergesort(A3, sizeofArray);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);



		break;
	case 4:
		cout << "Insert + Index with a random array[" << sizeofArray << "]" << endl;


		t1 = chrono::steady_clock::now();
		mergesortPosition(A4, Aposition4, sizeofArray);
		t2 = chrono::steady_clock::now();

		time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);





		break;
	default:
		cout << "Your choice don't exist. Try again.";
	}
	delete A1, A2, Aposition2, A3, A4, Aposition4;
	return time_span.count();
}
void runTestSet() {

	double durationTest = 0;

	cout << "CLASSIC INSERT : " << endl;
	durationTest = performanceDurationTest(1, 1);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(1, 10);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(1, 100);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(1, 1000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(1, 10000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(1, 50000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(1, 100000);
	cout << durationTest << endl;

	cout << "/***********************************************************/ \n\n";

	durationTest = performanceDurationTest(2, 1);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(2, 10);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(2, 100);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(2, 1000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(2, 10000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(2, 50000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(2, 100000);
	cout << durationTest << endl;

	cout << "/***********************************************************/ \n\n";

	durationTest = performanceDurationTest(3, 1);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(3, 10);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(3, 100);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(3, 1000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(3, 10000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(3, 50000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(3, 100000);
	cout << durationTest << endl;

	cout << "/***********************************************************/ \n\n";

	durationTest = performanceDurationTest(4, 1);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(4, 10);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(4, 100);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(4, 1000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(4, 10000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(4, 50000);
	cout << durationTest << endl;
	durationTest = performanceDurationTest(4, 100000);
	cout << durationTest << endl;

	cout << "/***********************************************************/ \n\n";

}
//***********************************************************************************************************