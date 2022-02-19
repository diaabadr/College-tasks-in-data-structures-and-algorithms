#include <iostream>
using namespace std;


int partition(int a[], int l, int h)
{
	int pivot = a[l];
	int i = l;
	int j = h;
	do {
		do { i++; } while (a[i] <= pivot && i < h);
		do { j--; } while (a[j] > pivot && j > l);
		if (i < j)
			swap(a[i], a[j]);
	} while (i < j);
	swap(a[l], a[j]);
	return j;
}

void QuickSort(int a[], int l, int h)
{
	int j;
	if (l < h)
	{
		j = partition(a, l, h);
		QuickSort(a, l, j);
		QuickSort(a, j + 1, h);
	}
}


int main()
{
	int a[] = { 50,70,60,90,40,80,10,20,30 };//5000 should be max integer
	QuickSort(a, 0, 9);
	for (auto elem : a)
		cout << elem << "   ";
}