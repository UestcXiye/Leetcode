#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

bool match(char &c1, char &c2)
{
	if (c1 == '(' && c2 == ')')
		return true;
	else
		return false;
}

int main()
{
	char exp[1000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> exp[i];
	stack<char> stk;
	for (int i = 0; i < n; i++)
	{
		if (exp[i] == '(')
			stk.push(exp[i]);
		else if (exp[i] == ')')
		{
			if (stk.empty())
			{
				cout << "括号匹配失败" << endl;
				system("pause");
				return 0;
			}
			char c = stk.top();
			if (match(c, exp[i]))
				stk.pop();
			else
			{
				cout << "括号匹配失败" << endl;
				system("pause");
				return 0;
			}
		}
		else
		{
			cout << "括号不合法" << endl;
			system("pause");
			return 0;
		}
	}
	if (!stk.empty())
	{
		cout << "括号匹配失败" << endl;
		system("pause");
		return 0;
	}
	cout << "括号匹配成功" << endl;
	system("pause");
	return 0;
}
