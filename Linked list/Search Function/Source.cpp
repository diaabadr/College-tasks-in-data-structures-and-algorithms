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
Node* search(Node *p,int key) // using Move to head techniqe to improve searching (linear search) 
{
	Node* q=NULL; 
	while (p)
	{
		if (p->data == key)
		{
			if (q)// if it's the first element so I don't need to move it 
			{
				q->Next = p->Next;
				p->Next = first;
				first = p;
			}
			return p;
		}
		q = p;
		p = p->Next;
	}
	return NULL;
}
int main()
{
	int a[] = { 1,2,3,4,5,6 };
	create(a, 6);
	Node* p = search(first, 6);
	if (p)
		cout << p->data << " Is found\n";
	else
		cout << "Not found";

}