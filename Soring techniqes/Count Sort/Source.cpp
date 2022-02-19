#include <iostream>
using namespace std;

int FindMax(int a[], int s)
{
	int max = a[1];
	for (int i = 0; i < s; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}


void CountSort(int a[], int s)
{
	int p = 0, q = 0;
	int max = FindMax(a, s);
	int* b = new int[max + 1];

	for (int i = 0; i < max + 1; i++)
		b[i] = 0;
	for (int i = 0; i < s; i++)
	{
		b[a[i]]++;
	}

	while (q < max + 1)
	{
		if (b[q] > 0)
		{
			a[p++] = q;
			b[q]--;
		}
		else
			q++;
	}

}


int main()
{
	int A[] = { 11,13,7,12,16,9,24,5,10,3 }, n = 10, i;

	CountSort(A, n);

	for (i = 0; i < 10; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}