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

vector<int> getNums(string version)
{
	int n = version.size(), begin = 0;
	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		if (version[i] == '.')
		{
			string temp = version.substr(begin, i - begin);
			nums.push_back(stoi(temp));
			begin = i;
		}
	}
	return nums;
}

int main()
{
	string version = "0.0.123.1";
	vector<int> nums = getNums(version);
	PrintVector(nums);

	system("pause");
	return 0;
}
