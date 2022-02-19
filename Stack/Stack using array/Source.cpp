#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
	int size;
	int top;
	T* st;
public:
	Stack()
	{
		size = 10;
		top = -1;
		st = new T[size];
	}
	Stack(int size)
	{
		this->size = size > 0 ? size : 0;
		top = -1;
		st = new T[this->size];
	}

	void push(T x)
	{
		if (IsFull())
			cout << "Stack overflow\n";
		else
		{
			top++;
			st[top] = x;
		}
	}

	bool IsFull()
	{
		return top == size - 1;
	}

	bool IsEmpty()
	{
		return top == -1;
	}
	T pop()
	{
		T x = -1;
		if (IsEmpty())
			cout << "Stack underflow\n";
		else
		{
			x = st[top];
			top--;
		}
		return x;
	}

	T peek(int index) //getting element by its index
	{
		T x = -1;
		if (top - index + 1 < 0)
			cout << "Invalid Index" << endl;
		else if (IsEmpty())
			cout << "Stack underflow\n";
		else
			x = st[top - index + 1];// formula to get the position from the index
		return x;
	}

	T stacktop()
	{
		if (IsEmpty())
			return -1;
		else
			return st[top];
	}

	void Display()
	{
		for (int i = top; i >= 0; i--)
			cout << st[i] << " ";
		cout << endl;
	}
};

int main()
{
	Stack<char> stk(5);
	stk.push('a');
	stk.push('b');
	stk.push('c');
	stk.push('d');
	stk.push('e');
	stk.push('f');

	stk.Display();

	cout << stk.peek(1) << endl;


	return 0;
}