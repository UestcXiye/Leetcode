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
				cout << "À¨ºÅÆ¥ÅäÊ§°Ü" << endl;
				system("pause");
				return 0;
			}
			char c = stk.top();
			if (match(c, exp[i]))
				stk.pop();
			else
			{
				cout << "À¨ºÅÆ¥ÅäÊ§°Ü" << endl;
				system("pause");
				return 0;
			}
		}
		else
		{
			cout << "À¨ºÅ²»ºÏ·¨" << endl;
			system("pause");
			return 0;
		}
	}
	if (!stk.empty())
	{
		cout << "À¨ºÅÆ¥ÅäÊ§°Ü" << endl;
		system("pause");
		return 0;
	}
	cout << "À¨ºÅÆ¥Åä³É¹¦" << endl;
	system("pause");
	return 0;
}
