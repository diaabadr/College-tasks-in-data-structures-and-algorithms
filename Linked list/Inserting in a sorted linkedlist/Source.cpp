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

void sortedInsert(Node* p, int element)
{
	Node* t = new Node();
	t->data = element;
	t->Next = NULL;
	if (p == NULL)
		first = t;
	else
	{
		if (t->data < p->data)
		{
			t->Next = first;
			first = t;
			return;
		}
		else if (p->data == t->data)
			return;
		Node* q = NULL;
		while (p!=NULL&&p->data < t->data)
		{
			q = p;
			p = p->Next;
		}
		t->Next = p;
		q->Next = t;

	}

}


int main()
{
	pushback(1);
	pushback(2);
	pushback(5);
	Display(first);
	sortedInsert(first, 4);
	cout << "\n";
	Display(first);
	cout << "\n";
	sortedInsert(first, 6);
	Display(first);

}