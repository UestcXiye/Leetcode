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
	vector<int> point1 = {1, 1};
	vector<int> point2 = {2, 2};
	vector<int> point3 = {2, 2};

	if (point3 == point2)
		cout << "Yes\n";

	system("pause");
	return 0;
}
