#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* Next;
}*first = NULL;

void create(int a[], int s)
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

void Insert(Node* p, int element, int position)
{
	if (position < 0 || position>count(first))
		return;
	Node* t = new Node();
	t->data = element;
	if (position == 0)
	{

		t->Next = first;
		first = t;
	}
	else
	{
		int i = 0;
		while (i < position - 1)
		{
			p = p->Next;
			i++;
		}
		t->Next = p->Next;
		p->Next = t;
	}
}
int main()
{
	int a[] = { 1,2,3,4,5,6 };
	create(a, 6);
	Insert(first, 7, 6);
	Display(first);


	/* we can use insert function instead of create to make a linked list
	like this
		Insert(first, 1, 0);
	    Insert(first, 7, 1);
		it will make a linked list have those elements
	*/

}