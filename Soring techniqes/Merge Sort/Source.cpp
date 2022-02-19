#include <iostream>
using namespace std;
void Merge(int a[], int l, int mid, int h)
{
	int i = l, k=l;
	int j = mid + 1;
	int b[100];
	while (i <= mid && j <= h)
	{
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	for (; i <= mid; i++)
		b[k++] = a[i];
	for (; j <= h; j++)
		b[k++] = b[j];
	for (i = l; i <= h; i++)
		a[i] = b[i];
}


void ImergeSort(int a[], int n)
{
	int p, i, l, h, mid;
	for (p = 2; p <= n; p = p * 2)
	{
		for (i = 0; i + p - 1 <= n; i = i + p) // i+p-1 for if we have 11 elements
		{
			l = i;
			h = i + p - 1;
			mid = (h + l) / 2;
			Merge(a, l, mid, h);
		}
	}
	if (p / 2 < n)
		Merge(a, 0, p / 2 - 1, n);
}
int main()
{
	int A[] = { 11,13,7,12,16,9,24,5,10,3 }, n = 10, i;

	ImergeSort(A, n);

	for (i = 0; i < 10; i++)
		cout << A[i];

	return 0;
}