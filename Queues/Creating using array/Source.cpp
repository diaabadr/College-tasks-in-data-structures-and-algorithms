#include <iostream>
using namespace std;
class Queue
{
private:
	int front;
	int rear;
	int size;
	int* Q;
public:
	Queue() 
	{ front = rear = -1;
	size = 10;
	Q = new int[size];
	}


	Queue(int size)
	{
		front = rear = -1;
		this -> size = size;
		Q = new int[this->size];
	}


	void enqueue(int x)
	{
		if (isFull())
			cout << "Queue Full\n";
		else
		{
			rear++;
			Q[rear] = x;
		}
	}


	int dequeue()
	{
		int x = -1;
		if (isEmpty())
			cout << "Queue is Empty\n";
		else
		{
			x = Q[front + 1];
			front++;
		}
		return x;
	}

	int peek()
	{
		if (isEmpty())
		{
			cout << "It's empty\n";
			return -1;
		}
		else
			return Q[front];
	}

	bool isFull()
	{
		return rear == size - 1;
	}

	bool isEmpty()
	{
		return front == rear;
	}
};


int main()
{
	Queue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.dequeue();
	return 0;
}