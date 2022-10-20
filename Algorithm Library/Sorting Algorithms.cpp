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
int BinarySearch(int arr[], int len, int element) 
{
	int pos = -1;
	int temp = 0;

		while (true)
		{
			int mid = temp + (len / 2);

			if (arr[mid] == element) {
				pos = mid;
				break;
			}
			else if (arr[mid] > element) {
				len /= 2;
			}
			else if (arr[mid] < element) {
				temp = len / 2;
				len = (len / 2);
			}
		}

	return pos;
}

int main()
{
	int arr[] = { 2, 4, 6, 8, 10, 12, 14 };
	int len = sizeof(arr) / sizeof(arr[0]);

	int element;
	int validPos;

	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << ' ';
	}

	cout << "\nInput number you want to find: ";
	cin >> element;

	cout << "\nInput position in array: ";
	cin >> validPos;

	// Linear Search
	auto startls = high_resolution_clock::now();
	int ls = LinearSearch(arr, len, element);
	auto stopls = high_resolution_clock::now();

	auto durationls = duration_cast<nanoseconds>(stopls - startls);

	if (ls == validPos)
	{
		cout << "Passed; ";
	}
	else {
		cout << "Failed; ";
	}

	cout << "Time taken by Linear Search: "
		<< durationls.count() << " nanoseconds" << endl;

	// Binary Search
	auto startbs = high_resolution_clock::now();
	int bs = BinarySearch(arr, len, element);
	auto stopbs = high_resolution_clock::now();

	auto durationbs = duration_cast<nanoseconds>(stopbs - startbs);

	if (ls == validPos)
	{
		cout << "Passed; ";
	}
	else {
		cout << "Failed; ";
	}

	cout << "Time taken by Binary Search: "
		<< durationbs.count() << " nanoseconds" << endl;
}