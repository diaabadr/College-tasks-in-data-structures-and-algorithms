#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
	int i, j, x;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (j > -1 && a[j] > x)  // j==-1 happened in stage 1  , a[j]>x failed in stage 2
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
int main()
{
	int A[] = { 11,13,7,12,16,9,24,5,10,3 }, n = 10, i;

	InsertionSort(A, n);

	for (i = 0; i < 10; i++)
		printf("%d ", A[i]);
	printf("\n");

	return
		0
		;
}