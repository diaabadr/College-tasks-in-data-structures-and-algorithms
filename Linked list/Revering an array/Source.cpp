#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* Next;
}*first = NULL, * last = NULL;

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

void Display(struct Node* p)
{
	while (p != NULL)
	{
		cout << p->data << "   ";
		p = p->Next;
	}
}

void pushback(int element)
{
	Node* t = new Node();
	t->data = element;
	t->Next = NULL;
	if (first == NULL)
	{
		first = last = t;
	}
	else
	{
		last->Next = t;
		last = t;
	}
}

void reverse(Node* p)
{
	Node* q, * r;
	q = r = NULL;
	while (p)
	{
		r = q;
		q = p;
		p = p->Next;
		q->Next = r;
	}
	first = q;
}
int main()
{
	pushback(1);
	pushback(2);
	pushback(2);
	pushback(3);
	pushback(3);
	pushback(3);
	Display(first);
	cout << endl;
	reverse(first);
	Display(first);
}