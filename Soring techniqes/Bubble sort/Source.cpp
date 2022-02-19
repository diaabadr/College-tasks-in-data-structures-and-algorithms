#include <iostream>
using namespace std;

void BubbleSort(int a[], int n)
{
	bool flag = true;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = false;
			}
		}
		if (flag) // for Adaptive case (if the array is already sorted)
			break;
	}
}

int main()
{
	int arr[] = { 8,5,7,3,2 };// max time case O(n^2)
	BubbleSort(arr,5);
	for (auto elem : arr)
		cout << elem << "   ";
	cout << endl;
	int arr1[] = { 1,2,3,4,5 }; // Adabtive case (Min time) O(n)
								// so Bubble algorithm is an adaptive algorithm
	BubbleSort(arr1, 5);
	for (auto elem : arr1)
		cout << elem << "   ";
}