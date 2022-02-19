#include <iostream>
using namespace std;
#define SIZE 10

int Hash_(int key)
{
	return key % SIZE;
}

int Probe(int H[],int key)
{
	int i = 0;
	while (H[(key + i) % SIZE]!=0)
		i++;
	return (key + i) % SIZE;
}

void Insert(int H[],int key)
{
	int index = Hash_(key);
	if (H[index] != 0)
		index = Probe(H, key);
	H[index] = key;
}

int Search(int H[], int key)
{
	int index = Hash_(key);
	int i = 0;
	while (H[(index + i) % 10] != key)
	{
		if (H[(index + i) % 10] == 0)
			return -1; // if it's not found
		i++;
	}
	return (index + i) % 10;
}

int main()
{
		int HT[10] = { 0 };

		Insert(HT, 12);
		Insert(HT, 25);
		Insert(HT, 35);
		Insert(HT, 26);

		int index = Search(HT, 35);
		printf("\nKey found at %d\n", index);
		return 0;

}