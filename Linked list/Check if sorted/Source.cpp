#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* Next;
}*head = NULL, * tail = NULL;

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
	if (head == NULL)
	{
		head = tail = t;
	}
	else
	{
		tail->Next = t;
		tail = t;
	}
}

bool isSorted(struct Node* p)
{
	if (p == NULL)
		return false;

	int	x = p->data;

	while (p != NULL)
	{
		if (p->data < x)
			return false;
		x = p->data;
		p = p->Next;
	}
	return true;

}
int main()
{
	pushback(1);
	pushback(2);
	pushback(3);
	pushback(4);
	pushback(8);
	pushback(7);
	Display(head);
	cout << endl;
	cout << isSorted(head) << endl;// testing of the function

}