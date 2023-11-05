#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

#define MAX_COST 1e5
#define MAX_N 1e5 + 1

void CountSort(vector<int> &costs)
{
	vector<int> cnt(MAX_N, 0);
	for (int &cost : costs)
		cnt[cost]++;
	int index = 0;
	for (int i = 0; i <= MAX_COST; i++)
		for (int j = 0; j < cnt[i]; j++)
		{
			costs[index] = i;
			index++;
		}
}

void PrintVector(vector<int> &vec)
{
	for (int &v : vec)
		cout << v << " ";
	cout << endl;
}

int main()
{
	string s = "1326#";

	int n = s.size();
	string ans;
	for (int i = 0; i < n; i++)
	{
		if (i + 2 < n && s[i + 2] == '#')
		{
			int pianyi = stoi(s.substr(i, 2)) - 1;
			cout << pianyi << endl;
			ans += (char)('a' + pianyi);
			i += 2;
		}
		else
			ans += (char)('a' + s[i] - '1');
	}
	cout << ans << endl;

	system("pause");
	return 0;
}
