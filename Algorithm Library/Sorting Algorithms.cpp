#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Linear Search is defined as a sequential search algorithm that starts
// at one end and goes through each element of a list until the desired
// element is found, otherwise the search continues till the end of the data set.
// It is the easiest searching algorithm
int LinearSearch(int arr[], int len, int element) {
	// Linear Search
	int pos = -1;

	// Checks element by ele
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == element) {
			pos = i;
			break;
		}
	}

	return pos;
}

// Binary Search is a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. 
// The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Log n). 
int BinarySearch(int arr[], int low, int high, int x)
{
	if (high >= low) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return BinarySearch(arr, low, mid - 1, x);

		return BinarySearch(arr, mid + 1, high, x);
	}

	return -1;
}

int main()
{
	int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42,44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64 };
	int len = sizeof(arr) / sizeof(arr[0]);

	int element;
	int validPos;

	// Linear Search
	cout << "LINEAR SEARCH" << endl;
	cout << "_____________\n\n";

	for (int i = 0; i < len; i++)
	{
		validPos = i;

		auto startls = high_resolution_clock::now();
		int ls = LinearSearch(arr, len, arr[i]);
		auto stopls = high_resolution_clock::now();

		auto durationls = duration_cast<nanoseconds>(stopls - startls);

		if (ls == validPos)
		{
			cout << "Passed; Output: " << ls << "; ";
		}
		else {
			cout << "Failed; Output: " << ls << "; ";
		}

		cout << "Time taken by Linear Search: "
			<< durationls.count() << " nanoseconds" << endl;
	}

	cout << "\n\n\n";

	// Binary Search
	cout << "BINARY SEARCH" << endl;
	cout << "_____________\n\n";

	for (int i = 0; i < len; i++)
	{
		validPos = i;

		auto startbs = high_resolution_clock::now();
		int bs = BinarySearch(arr, 0, len - 1, arr[i]);
		auto stopbs = high_resolution_clock::now();

		auto durationbs = duration_cast<nanoseconds>(stopbs - startbs);

		if (bs == validPos)
		{
			cout << "Passed; Output: " << bs << "; ";
		}
		else {
			cout << "Failed; Output: " << bs << "; ";
		}

		cout << "Time taken by Binary Search: "
			<< durationbs.count() << " nanoseconds" << endl;
	}

	cout << "\n\n\n";
}