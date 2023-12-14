#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> &vec);
string delSpaceStr(string s);

int main()
{
	string s = "    aaabbb    ";

	cout << delSpaceStr(s) << endl
		 << delSpaceStr(s).length() << endl;

	system("pause");
	return 0;
}

void PrintVector(vector<int> &vec)
{
	for (int &v : vec)
		cout << v << " ";
	cout << endl;
}

string delSpaceStr(string s)
{
	int n = s.length(), i = 0, j = n - 1;
	while (i < n && s[i] == ' ')
		i++;
	while (j >= 0 && s[j] == ' ')
		j--;
	if (i <= j)
		return s.substr(i, j - i + 1);
	return "";
}
