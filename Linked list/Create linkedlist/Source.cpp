#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* Next;
}*first=NULL;


void create(int a[],int s)
{
	first = new Node();
	Node* t, * last;
	first->data = a[0];
	first->Next = NULL;
	last = first;
	for (int i = 1; i < s; i++)
	{
		t = new Node();
		t->data = a[i];
		t->Next = NULL;
		last->Next = t;
		last = t;
	}
}

void display(Node *p)
{
	while (p != NULL)
	{
		cout << p->data << "    ";
		p = p->Next;
	}
}

void RDisplay(struct Node* p)  // reverse printing 
{
	if (p != NULL)
	{
		RDisplay(p->Next);
		cout << p->data << "    ";

	}
}

int count(Node *p)
{

	//another way to write the fun
	/*if (p)   *means if p ins not pointing to NULL*
		return 0;
	return count(p->Next) + 1;
	*/
	int c = 0;
	while (p != NULL)
	{
		c++;
		p = p->Next;
	}
	return c;
}

int add(Node* p)
{
	int sum = 0;
	while (p)
	{
		sum += p->data;
		p = p->Next;
	}
	return sum;
}

int Max(Node* p)
{
	int max = p->data;
	p = p->Next;
	while (p)
	{
		
		if (p->data > max)
			max = p->data;
		p = p->Next;
	}
	return max;
}

int Search(int key) {
	Node* ptr = first;
	int i = 0;
	while (ptr != NULL)
	{
		if (ptr->data == key)
			return i;
		ptr = ptr->Next;
		i++;
	}
	return -1;
}
int main()
{
	int a[] = { 1,2,3,4,5,6 };
	create(a, 6);
	display(first);
	cout << Search(7);
	cout << "\nnumber of nodes is " << count(first);
	cout << "\nsum of all elements is " << add(first);
	cout << "\nMax int of all elements is " << Max(first);
}