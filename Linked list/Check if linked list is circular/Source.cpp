#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* Next;
}*first = NULL, * second = NULL, * third = NULL;


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

int IsLoop(Node* p)// check if it's circular
{
	Node* q = p;
	while (p && q)
	{
		p = p->Next;
		q = q->Next->Next;
		if (q == p)
			return true;
	}
	return false;
}


int main()
{
	int a[] = { 1,3,5,7,9,11 };
	int b[] = { 2,4,6,8,10,12 };
	create1(a, 6);
	create2(b, 6);
	Node* t1 = second->Next->Next->Next->Next->Next;
	t1->Next = second->Next->Next;// to make the second linked list loop
	if (IsLoop(first))
		cout << "Loop\n";
	else
		cout << "Linear\n";
}