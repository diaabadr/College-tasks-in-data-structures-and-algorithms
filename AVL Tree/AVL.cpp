#include <iostream>
#include "AVL.h"
#include <vector>
using namespace std;

template <class T>
void UserInput(AVL<T>& tree, int numOfOper);
int main(int argc, char** argv)
{
	/****** My test for AVL tree ****/
	//Note : operation 8 means delete an element
		/*input : 0 12\r\n1 12\r\n1 8\r\n1 13\r\n1 3\r\n1 9\r\n1 14\r\n1 2\r\n1 4\r\n1 5\r\n4 1\r\n8 13\r\n4 1*/
		/*output if it's not AVL : "12 8 3 2 4 5 9 13 14 \r\n12 8 3 2 4 5 9 14 "*/
		/*output if its AVL : "12 4 3 2 8 5 9 13 14 \r\n 4 3 2 12 8 5 9 14 "*/


	vector<int> v;
	int treeSize, numOfOperation;
	cin >> treeSize >> numOfOperation;
	int elem;
	for (int i = 0; i < treeSize; i++)
	{
		cin >> elem;
		v.push_back(elem);
	}
	AVL<int> tree(v);
	UserInput(tree, numOfOperation); // testing the function
}
template <class T>
void UserInput(AVL<T>& tree, int numOfOper)
{
	T elem;
	for (int i = 0; i < numOfOper; i++)
	{
		int opType;
		cin >> opType;
		switch (opType)
		{
		case 1:
			cin >> elem;
			tree.insert(elem);
			break;
		case 2:
			cin >> elem;
			cout << tree.search(elem) << " \n";
			break;
		case 3:
			cin >> opType;
			if (opType == 1)
				tree.inorder_rec();
			else if (opType == 2)
				tree.inorder_it();
			break;
		case 4:
			cin >> opType;
			if (opType == 1)
				tree.preorder_rec();
			else if (opType == 2)
				tree.preorder_it();
			break;
		case 5:
			cin >> opType;
			if (opType == 1)
				tree.postorder_rec();
			else if (opType == 2)
				tree.postorder_it();
			break;
		case 6:
			tree.breadth_traversal();
			break;
		case 7:
			cout << tree.size() << " \n";
			break;
		case 8:    // case to tese delete function
			cin >> elem;
			tree.Delete(elem);
			break;
		default:
			break;
		}
	}
}
