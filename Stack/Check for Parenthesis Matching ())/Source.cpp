#include <iostream>
#include <string>
using namespace std;
struct Node
{
	char data;
	struct Node* next;
}*top = NULL;

void push(char x)
{
	struct Node* t;
	t = new Node();

	if (t == NULL)
		cout<<"stack is full\n";
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}

}
char pop()
{
	struct Node* t;
	char x = -1;

	if (top == NULL)
		cout<<"Stack is Empty\n";
	else
	{
		t = top;
		top = top->next;
		x = t->data;
		delete t;
	}
	return x;
}
void Display()
{
	struct Node* p;
	p = top;
	while (p != NULL)
	{
		cout << p->data<<"   ";
		p = p->next;
	}
	cout<<"\n";
}

bool isBalanced(char* exp)
{
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
			push(exp[i]);
		else if (exp[i] == ')')
		{
			if (top == NULL)
				return false;
			pop();
		}
	}
	return top == NULL;
}

int main()
{

	char* exp = new char[20];
	strcpy_s(exp,20,"((a+b)*(c-d))");

	cout<<isBalanced(exp);

	return 0;
}