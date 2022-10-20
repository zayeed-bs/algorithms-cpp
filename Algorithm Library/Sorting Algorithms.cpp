#include <iostream>
using namespace std;

// Linear Search is defined as a sequential search algorithm that starts
// at one end and goes through each element of a list until the desired
// element is found, otherwise the search continues till the end of the data set.
// It is the easiest searching algorithm
int LinearSearch(int arr[], int len) {
	// Linear Search
	int element;
	cin >> element;


	int pos = -1;


	for (int i = 0; i < len; i++)
	{
		if (arr[i] == element) {
			pos = i;
			break;
		}
	}

	return pos;
}



int main()
{
	int arr[] = { 0,1,2,3,4,5,6 };
	int len = sizeof(arr) / sizeof(arr[0]);

	LinearSearch(arr, len);
}