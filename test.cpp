#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
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

void PrintVector(vector<int> &vec);

int main()
{
	string s = "loveleetcode";
	int n = s.size();
	int i = 1;
	cout << s.substr(0, i + 1) << endl;
	cout << s.substr(i, n - i) << endl;

	system("pause");
	return 0;
}

void PrintVector(vector<int> &vec)
{
	for (int &v : vec)
		cout << v << " ";
	cout << endl;
}