#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* Next;
}*first = NULL,*second=NULL;


void create1(int a[], int s)
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


void create2(int a[], int s)
{
	second = new Node();
	Node* t, * last;
	second->data = a[0];
	second->Next = NULL;
	last = second;
	for (int i = 1; i < s; i++)
	{
		t = new Node();
		t->data = a[i];
		t->Next = NULL;
		last->Next = t;
		last = t;
	}
}
void display(Node* p)
{
	while (p != NULL)
	{
		cout << p->data << "    ";
		p = p->Next;
	}
}


int count(Node* p)
{
	int c = 0;
	while (p != NULL)
	{
		c++;
		p = p->Next;
	}
	return c;
}


void concat(Node *p)
{
	while (p->Next != NULL)
	{
		p = p->Next;
	}
	p->Next = second;
	second = NULL;
}

int main()
{
	int a[] = { 1,2,3,4,5,6 };
	create1(a, 6);
	create2(a, 6);
	display(first);
	cout << endl;
	concat(first);
	display(first);
}