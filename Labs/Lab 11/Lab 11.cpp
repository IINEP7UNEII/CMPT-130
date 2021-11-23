#include <iostream>
using namespace std;

// Function Prototypes
int iterativeSearch(int arr[], int size, int target);
int recursiveSearch(int arr[], int next, int target);
void printSmallArray(int arr[], int n);

int main()
{
    int size = 11;
	int arr[] = { 1,3,5,7,9,11,13,15,17,19,21 };
	int target = 0;
 
	cout << "arr = ";
	printSmallArray(arr, size);
	cout << endl << endl;
 
	cout << "ITERATIVE SEARCH TESTS" << endl;
	cout << "search for " << target << ": " << iterativeSearch(arr, size, target) << endl;
	target = 1;
	cout << "search for " << target << ": " << iterativeSearch(arr, size, target) << endl;
	target = 21;
	cout << "search for " << target << ": " << iterativeSearch(arr, size, target) << endl;
	target = 12;
	cout << "search for " << target << ": " << iterativeSearch(arr, size, target) << endl;
	target = 13;
	cout << "search for " << target << ": " << iterativeSearch(arr, size, target) << endl;
 
	cout << endl <<  "RECURSIVE SEARCH TESTS" << endl;
	target = 0;
	cout << "search for " << target << ": " << recursiveSearch(arr, size-1, target) << endl;
	target = 1;
	cout << "search for " << target << ": " << iterativeSearch(arr, size-1, target) << endl;
	target = 21;
	cout << "search for " << target << ": " << recursiveSearch(arr, size-1, target) << endl;
	target = 12;
	cout << "search for " << target << ": " << recursiveSearch(arr, size-1, target) << endl;
	target = 13;
	cout << "search for " << target << ": " << recursiveSearch(arr, size-1, target) << endl;

    system("pause");
}

// Function to print an array on one line like this:
//    {2,5,3,9,7}
//    Warning - only useful for small arrays!
// PARAM: arr - array to be printed, n - size of arr
// POST: contents of arr are printed to standard output
void printSmallArray(int arr[], int n)
{
	cout << "{";
	for (int i = 0; i < n; ++i) 
    {
		cout << arr[i];
		if (i != n - 1) 
        {
			cout << ",";
		}
	}
	cout << "}";
}

int iterativeSearch(int arr[], int size, int target)
{
    for (int count = 0; count < size; ++count)
    {
        if (arr[count] == target)
        {
            return count;
        }
    }
    return -1;
}

int recursiveSearch(int arr[], int next, int target)
{
    if (next < 0)
    {
        return -1;
    }
    else if (arr[next] == target)
    {
        return next;
    }
    else
    {
        return recursiveSearch(arr, --next, target);
    }
}