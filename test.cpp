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
	vector<int> nums = {2, -3, -1, 5, -4};
	int k = 2;

	int n = nums.size();
	int count_neg = 0, min_abs_idx = 0;
	bool zero = false;

	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i++)
	{
		if (nums[i] < 0)
			count_neg++;
		else if (nums[i] == 0)
			zero = true;
		if (abs(nums[i]) < abs(nums[min_abs_idx]))
			min_abs_idx = i;
	}

	if (k <= count_neg)
	{
		int index = 0;
		while (k--)
		{
			nums[index] = -nums[index];
			index++;
		}
	}
	else
	{
		for (int i = 0; i < count_neg; i++)
			nums[i] = -nums[i];
		if ((k - count_neg) % 2 == 1 && zero == false)
			nums[min_abs_idx] = -nums[min_abs_idx];
	}

	cout << count_neg << endl
		 << min_abs_idx << endl
		 << zero << endl;

	PrintVector(nums);

	cout << accumulate(nums.begin(), nums.end(), 0) << endl;

	system("pause");
	return 0;
}
