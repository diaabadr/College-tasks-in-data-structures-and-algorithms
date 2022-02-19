#include <iostream>
using namespace std;
struct Node {
	Node* previous;
	int data;
	Node* Next;
}*first=NULL,*last=NULL;
void create(int a[], int s)
{
	Node* t;
	first = new Node();
	first->data = a[0];
	first->Next = first->previous = NULL;
	last = first;
	for (int i = 1; i < s; i++)
	{
		t = new Node();
		t->data = a[i];
		t->Next = last->Next;
		t->previous = last;
		last->Next = t;
		last = t;
	}
}

void display(Node* p)
{
	while (p)
	{
		cout << p->data << "   ";
		p = p->Next;
	}
}

int main()
{
	int a[] = { 1,2,3,4,6 };
	create(a, 5);
	display(first);
}