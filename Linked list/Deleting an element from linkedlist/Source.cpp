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

void delete_(Node* p, int position)
{
	if (position<1 || position>count(p))
		return;
	if (position == 1)
	{
		first = p->Next;
		delete p;
	}
	else
	{
		Node* q = NULL;
		for (int i = 0; i < position - 1; i++)
		{
			q = p;
			p = p->Next;
		}
		q->Next = p->Next;
		delete p;
	}
}
int main()
{
	pushback(1);
	pushback(2);
	pushback(5);
	pushback(4);
	pushback(6);
	pushback(3);
	Display(first);
	cout << endl;

	delete_(first, 3);
	Display(first);

}