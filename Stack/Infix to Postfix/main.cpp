#include <iostream>
#include <string>
#include <stack>
using namespace std;

int isOperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 0;
	else
		return 1;
}

int Priority(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	return 0;
}

string InfixtoPostfix(string infix)
{
	stack<char> st;
	string postfix;
	for (int i = 0; i < infix.length(); i++)
	{
		if (isOperand(infix[i]))
			postfix.push_back(infix[i]);
		else if (st.empty())
			st.push(infix[i]);
		else
		{
			if (Priority(infix[i]) > Priority(st.top()))
				st.push(infix[i]);
			else {
				while (!st.empty()) {
					postfix.push_back(st.top());
					st.pop();
				}
				st.push(infix[i]);
			}
		}

	}
	while (!st.empty())
	{
		postfix.push_back(st.top());
		st.pop();
	}
	return postfix;
}


int main()
{
	string infix = "a+b*c+d*e+f*g";
	cout << InfixtoPostfix(infix);
}