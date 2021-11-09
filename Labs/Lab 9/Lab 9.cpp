// lab9: insertion sort demo
// John Edgar November 2021
 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
// Function Protootypes
void printArray(int arr[], int n);
long long insertionSort(int arr[], int size);
int* getSequence(int n, int start, int gap);
int* getRandomArray(int n);
 
int main()
{
	srand(time(0));
 
	int n = 100000;
	cout << endl << "n = " << n << endl << "------------";
 
	int* sortedArr = getSequence(n, 0, 1);
	cout << endl << "Work estimate on sorted array:   ";
	cout << setw(12) << insertionSort(sortedArr, n) << endl;
 
	int* reversedArr = getSequence(n, n, -1);
	cout << "Work estimate on reversed array: ";
	cout << setw(12) << insertionSort(reversedArr, n) << endl;
 
	int* randomArr = getRandomArray(n);
	cout << "Work estimate on random array:   ";
	cout << setw(12) << insertionSort(randomArr, n) << endl;
 
	// Clean up dynamically allocated memory
	delete[] sortedArr;
	delete[] reversedArr;
	delete[] randomArr;
 
	cout << endl << endl;
	system("pause");
}
 
// Function to print an array on one line like this:
//    {2,5,3,9,7}
//    Warning - only useful for small arrays!
// PARAM: arr - array to be printed, n - size of arr
// POST: contents of arr are printed to standard output
void printArray(int arr[], int n)
{
	cout << "{";
	for (int i = 0; i < n; ++i) {
		cout << arr[i];
		if (i != n - 1) {
			cout << ",";
		}
	}
	cout << "}";
}
 
// Sorts an array using the insertion sort algorithm
// PARAM: arr - array to be sorted, n - size of arr
// POST: arr is sorted
long long insertionSort(int arr[], int size)
{
	long long work = 0;
	for (int i = 1; i < size; ++i) 
    {
		int temp = arr[i];
		int pos = i;
 
		// Shuffle up all sorted items > arr[i]
		work++;
		while (pos > 0 && arr[pos - 1] > temp) 
        {
			work++;
			arr[pos] = arr[pos - 1];
			pos--;
		} //while
 
		// Insert the current item
		arr[pos] = temp;
	}
 
	return work;
}
 
// Returns a pointer to a sequence of integers with a linear progression
// PARAM: n - number of values in sequence
//        start - first value in sequence
//        gap between values in sequence
// POST: returns array with n values starting with start, separated by gap
int* getSequence(int n, int start, int gap)
{
	int next = start;
	int* result = new int[n];
 
	for (int i = 0; i < n; ++i) {
		result[i] = next;
		next += gap;
	}
	return result;
}
 
// Returns a pointer to a an array of random integers
// PARAM: n - number of values in array
// POST: returns array with n random values from 0 to n
int* getRandomArray(int n)
{
	int* result = new int[n];
	for (int i = 0; i < n; ++i) {
		result[i] = rand() % n;
	}
	return result;
}