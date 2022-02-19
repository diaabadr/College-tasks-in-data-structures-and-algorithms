#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* Next;
}*first = NULL,*last=NULL;

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
	if (first==NULL)
	{
		first = last = t;
	}
	else
	{
		last->Next = t;
		last = t;
	}
}
int main()
{
	int a[] = { 1,2,3,4,5,6 };
	pushback(1);
	pushback(2);
	pushback(3);
	Display(first);

}