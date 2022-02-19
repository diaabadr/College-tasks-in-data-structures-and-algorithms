#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* Next;
}*first = NULL, * second = NULL,*third=NULL;


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


void Merge(Node* p,Node *q)
{
	Node* last;
	if (p->data < q->data)
	{
		third = last = p;
		p = p->Next;
		third->Next = NULL;
	}
	else
	{
		third = last = q;
		q = q->Next;
		third->Next = NULL;
	}
	while (p && q)
	{
		if (p->data < q->data)
		{
			last->Next = p;
			last = p;
			p = p->Next;
			last->Next = NULL;
		}
		else
		{
			last->Next = q;
			last = q;
			q = q->Next;
			last->Next = NULL;
		}
	}
	if (p)
		last->Next = p;
	else
		last->Next = q;
}


int main()
{
	int a[] = { 1,3,5,7,9,11 };
	int b[] = { 2,4,6,8,10,12 };
	create1(a, 6);
	create2(b, 6);
	display(first);
	display(second);
	cout << endl;
	Merge(first,second);
	display(third);
}