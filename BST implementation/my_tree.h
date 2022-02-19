#ifndef MY_TREE_H
#define MY_TREE_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

template <class T>
class MyTree
{

	struct Node
	{
		Node* lChild;
		T data;
		Node* rChild;
	};

private:
	Node* root;

public:
	MyTree() : root(NULL) {}

	MyTree(vector<T> elements)
	{
		root = NULL;
		sort(elements.begin(), elements.end());
		root = insertforVector(elements, 0, elements.size() - 1);
	}

	Node* insertforVector(vector <T> v, int start, int end)
	{
		if (start > end)
			return NULL;
		int mid = (start + end) / 2;
		Node* p = newNode(v[mid]);

		p->lChild = insertforVector(v, start, mid - 1);
		p->rChild = insertforVector(v, mid + 1, end);
		return p;
	}

	Node* newNode(T key)
	{
		Node* t = new Node();
		t->data = key;
		t->lChild = t->rChild = NULL;
		return t;
	}
	bool search(T key)
	{
		Node* p = root;
		while (p != NULL)
		{
			if (key == p->data)
				return true;
			if (key > p->data)
				p = p->rChild;
			else
				p = p->lChild;
		}
		return false;
	}

	void insert(T key)
	{
		Node* t = root;
		Node* p = NULL, * q = NULL;
		if (root == NULL)
		{
			p = new Node();
			p->data = key;
			p->lChild = p->rChild = NULL;
			root = p;
			return;
		}
		while (t != NULL)
		{
			q = t;
			if (key > t->data)
				t = t->rChild;
			else if (key < t->data)
				t = t->lChild;
			else
				return;
		}
		p = new Node();
		p->data = key;
		p->lChild = p->rChild = NULL;
		if (key > q->data)
			q->rChild = p;
		else
			q->lChild = p;
	}

	void inorder_rec()
	{
		inorder_rec(root);
		cout << endl;
	}

	void inorder_rec(Node* p)
	{
		if (p != NULL)
		{
			inorder_rec(p->lChild);
			cout << p->data << " ";
			inorder_rec(p->rChild);
		}
		
	}
	void preorder_rec()
	{
		preorder_rec(root);
		cout << endl;
	}

	void preorder_rec(Node* p)
	{
		if (p != NULL)
		{
			cout  << p->data << " ";
			preorder_rec(p->lChild);
			preorder_rec(p->rChild);
		}
	}

	void postorder_rec()
	{
		postorder_rec(root);
		cout << endl;
	}

	void postorder_rec(Node* p)
	{
		if (p != NULL)
		{
			postorder_rec(p->lChild);
			postorder_rec(p->rChild);
			cout << p->data << " ";
		}
	}

	void inorder_it()
	{
		stack<Node*> st;
		Node* p = root;
		while (p != NULL || !st.empty())
		{
			if (p != NULL)
			{
				st.push(p);
				p = p->lChild;
			}
			else
			{
				p = st.top();
				st.pop();
				cout << p->data << " ";
				p = p->rChild;
			}
		}
		cout << endl;
	}

	void preorder_it()
	{
		stack<Node*> st;
		Node* p = root;
		while (p != NULL || !st.empty())
		{
			if (p != NULL)
			{
				cout  << p->data << " ";
				st.push(p);
				p = p->lChild;
			}
			else
			{
				p = st.top();
				st.pop();
				p = p->rChild;
			}
		}
		cout << endl;
	}

	void postorder_it()
	{
		stack<Node*> st;
		Node* p = root;
		if (p == NULL)
			return;
		do
		{
			while (p != NULL)
			{
				if (p->rChild != NULL)
					st.push(p->rChild);
				st.push(p);
				p = p->lChild;
			}
			p = st.top();
			st.pop();
			if (!st.empty())
			{
				if (p->rChild != NULL && st.top() == p->rChild)
				{
					st.pop();
					st.push(p);
					p = p->rChild;
				}
				else
				{
					cout  << p->data << " ";
					p = NULL;
				}
			}
			else
			{
				cout << p->data << " ";
				p = NULL;
			}

		} while (!st.empty());
		cout << endl;
	}

	void breadth_traversal()
	{
		if (root == NULL)
			return;
		queue<Node*> q;
		Node* p = root;
		cout  << p->data << " ";
		q.push(p);
		while (!q.empty())
		{
			p = q.front();
			q.pop();
			if (p->lChild)
			{
				cout  << p->lChild->data << " ";
				q.push(p->lChild);
			}
			if (p->rChild)
			{
				cout  << p->rChild->data << " ";
				q.push(p->rChild);
			}
		}
		cout << endl;
	}

	int size() { return size(root); }

	int size(Node* p)
	{
		if (p != NULL)
			return size(p->lChild) + size(p->rChild) + 1;
		return 0;
	}

	int Height(Node* p)
	{
		int x, y;
		if (p == NULL)
			return 0;
		x = Height(p->lChild);
		y = Height(p->rChild);
		return x > y ? x + 1 : y + 1;
	}

	Node* InPredecessor(Node* p)
	{
		while (p && p->rChild)
			p = p->rChild;
		return p;
	}

	Node* InSuccessor(Node* p)
	{
		while (p && p->lChild)
			p = p->lChild;
		return p;
	}

	bool Delete(int key)
	{
		Node* p = Delete(root, key);
			if (p != NULL)
			{
				if (root == NULL)
					delete p;
				return true;
			}
		return false;
	}

	Node* Delete(Node* p, T key)
	{
		Node* q = NULL;
		if (p == NULL)
			return NULL;

		if (p->lChild == NULL && p->rChild == NULL)
		{
			if (p == root)

				if (root->data == key)
				{
					root = NULL;
					delete p;
					return new Node(); // this just in case we have root==key and have no children so make the function
									   //doesn't return NULL because here the deletion case will delete so to make it
									   // doesn't return NULL for handling of the  previous function
										//don't worry about memory I will delete this new node in the previous delete function
				}
				else
					return NULL;

			delete p;
			return NULL;
		}
		if (key < p->data)
			p->lChild = Delete(p->lChild, key);
		else if (key > p->data)
			p->rChild = Delete(p->rChild, key);
		else
		{
			if (Height(p->lChild) > Height(p->rChild))
			{
				q = InPredecessor(p->lChild);
				p->data = q->data;
				p->lChild = Delete(p->lChild, q->data);
			}
			else
			{
				q = InSuccessor(p->rChild);
				p->data = q->data;
				p->rChild = Delete(p->rChild, q->data);
			}
		}
		return p;
	}
};
#endif