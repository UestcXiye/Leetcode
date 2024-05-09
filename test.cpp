#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// 方法一：使用toupper()

string toUpperMethod1(const string &s)
{
	string res = s;
	for (char &c : res)
		if (islower(c))
			c = toupper(c);
	return res;
}

// 方法二：算术运算

string toUpperMethod2(const string &s)
{
	string res = s;
	for (char &c : res)
		if (islower(c))
			c -= 'a' - 'A';
	return res;
}

int main()
{
	string s = "abc123";
	cout << toUpperMethod1(s) << endl;
	cout << toUpperMethod2(s) << endl;
	getchar();
	return 0;
}