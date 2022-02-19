#include <iostream>
using namespace std;

void SelectionSort(int a[],int n)  // Selection algorithm is not adaptive (always take max time) and not stable 
{
	int i, j, k;
	for ( i = 0; i < n - 1; i++)
	{
		for (j = k = i; j < n; j++)
		{
			if (a[j] < a[k])
				k = j;
		}
		swap(a[k], a[i]);
	}
}

int main()
{
	int A[] = { 11,13,7,12,16,9,24,5,10,3 }, n = 10, i;

	SelectionSort(A, n);

	for (i = 0; i < 10; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}