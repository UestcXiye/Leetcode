#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<int> counts;
	stack<string> strs;

	int n = s.size();
	int i = 0;
	while (i < n)
	{
		// 数字
		int j = i + 1;
		while (j < n && s[j] != '[')
			j++;
		counts.push(stoi(s.substr(i, j - i)));
		// '['之后
		i = j + 1;
		j = i + 1;
		while (j < n && s[j] != ']')
			j++;
		strs.push(s.substr(i, j - i));
		i = j + 1;
	}

	vector<string> tmps;
	while (!counts.empty())
	{
		string tmp;
		int cnt = counts.top();
		counts.pop();
		string sub = strs.top();
		strs.pop();
		for (int k = 0; k < cnt; k++)
			tmp += sub;
		tmps.push_back(tmp);
	}
	string res;
	for (int i = tmps.size() - 1; i >= 0; i--)
		res += tmps[i];
	cout << res << endl;

	system("pause");
	return 0;
}