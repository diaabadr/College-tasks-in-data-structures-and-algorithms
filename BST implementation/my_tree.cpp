#include <iostream>
#include "my_tree.h"
#include <vector>
using namespace std;

template <class T>
void UserInput(MyTree<T> &tree, int numOfOper);
int main(int argc, char **argv)
{

	/****** testing the root deletion ********/
	/*tree.insert(5);
	tree.insert(4);
	tree.insert(7);
	tree.insert(6);
	tree.breadth_traversal();
	cout << tree.Delete(5)<<endl;
	tree.breadth_traversal();*/

	vector<int> v;
	int treeSize, numOfOperation;
	cin >> treeSize >> numOfOperation;
	int elem;
	for (int i = 0; i < treeSize; i++)
	{
		cin >> elem;
		v.push_back(elem);
	}
	MyTree<int> tree(v);
	UserInput(tree, numOfOperation); // testing the function
}
template <class T>
void UserInput(MyTree<T> &tree, int numOfOper)
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
