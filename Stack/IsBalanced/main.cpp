#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool IsBalanced(string st)
{
	stack<char> s;

	for (int i = 0; i < st.length(); i++)
		// push if opening bracket
		if (st[i] == '(' || st[i] == '[' || st[i] == '{')
			s.push(st[i]);
		else
		{
			if (!s.empty())
			{
				char temp = s.top();

				s.pop();

				if (st[i] == ')' && temp != '(')
				{
					return false;
				}
				if (st[i] == ']' && temp != '[')
				{
					return false;
				}
				if (st[i] == '}' && temp != '{')
				{
					return false;
				}
			}
			// if stack is empty, not balanced
			else
			{
				return false;
			}
		}

	return s.empty();
}


int main()
{
	string s = "(){}([])";

	cout << IsBalanced(s);

}