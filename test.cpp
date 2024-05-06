#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <vector>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution
{
private:
	const int MOD = 1e9 + 7;

public:
	int minCostToEqualizeArray(vector<int> &nums, int cost1, int cost2)
	{
		int n = nums.size();
		int maxNum = *max_element(nums.begin(), nums.end());

		// 计算一开始每个桶里有几个石头
		long long diffSum = 0;
		int maxDiff = 0;
		for (int x : nums)
		{
			int det = maxNum - x;
			diffSum += det;
			maxDiff = max(maxDiff, det);
		}

		// 排除特殊情况
		if (nums.size() <= 2 || cost1 * 2 <= cost2)
			return diffSum * cost1 % MOD;

		long long ans = 1e18;
		// 从 maxNum 到 maxNum * 2 枚举目标数
		for (int i = maxNum; i <= 2 * maxNum; i++)
		{
			long long cost = 0LL;
			if (maxDiff > diffSum - maxDiff)
			{
				// 情况 1
				cost += (diffSum - maxDiff) * cost2;
				long long rem = maxDiff - (diffSum - maxDiff);
				cost += rem * cost1;
			}
			else
			{
				// 情况 2
				cost = diffSum / 2 * cost2;
				if (diffSum & 1)
					cost += cost1;
			}
			ans = min(ans, cost);
			// 目标数每增加 1，s 增加 n，m 增加 1
			diffSum += n;
			maxDiff++;
		}
		return ans % MOD;
	}
};

int main()
{
	cout << 1 << endl;

	system("pause");
	return 0;
}