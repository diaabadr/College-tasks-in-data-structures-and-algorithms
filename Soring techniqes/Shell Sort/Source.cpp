#include <iostream>
using namespace std;

void ShellSort(int a[],int s)
{
	int g, i, j,temp;
	for (g = s / 2; g >= 1; g = g / 2)
	{
		for (i = g; i < s; i++)
		{
			temp = a[i];
			j = i - g;
			while (j >= 0 && a[j] > temp)
			{
				a[j + g] = a[j];
				j = j - g;
			}
			a[j + g] = temp;
		}
	}
}


int main()
{
	int A[] = { 11,13,7,12,16,9,24,5,10,3 }, n = 10, i;

	ShellSort(A, n);

	for (i = 0; i < 10; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}
