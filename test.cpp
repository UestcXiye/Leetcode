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
bool cmp1(int i, int j)
{
	return i < j;
}
bool cmp2(const int &i, const int &j)
{
	return i > j;
}

void PrintVector(vector<int> &vec);

int main()
{
	vector<int> arr{3, 5, 6, 6};
	int max_num_index = max_element(arr.begin(), arr.end()) - arr.begin();
	cout << max_num_index << endl;
	if (is_sorted(arr.begin(), arr.begin() + max_num_index + 1, cmp1))
		cout << "Sorted\n";
	else
		cout << "Not Sorted\n";
	if (is_sorted(arr.begin() + max_num_index + 1, arr.end(), cmp2))
		cout << "Sorted\n";
	else
		cout << "Not Sorted\n";
	system("pause");
	return 0;
}

void PrintVector(vector<int> &vec)
{
	for (int &v : vec)
		cout << v << " ";
	cout << endl;
}