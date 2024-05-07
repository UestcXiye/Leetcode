/*
 * @lc app=leetcode.cn id=3139 lang=cpp
 *
 * [3139] 使数组中所有元素相等的最小开销
 */

// @lc code=start
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
        long long diffSum = 0LL;
        int maxDiff = INT_MIN;
        for (int &x : nums)
        {
            int diff = maxNum - x;
            diffSum += diff;
            maxDiff = max(maxDiff, diff);
        }

        // 情况一
        if (n <= 2)
            return (diffSum * cost1) % MOD;
        // 情况二
        if (cost1 * 2 <= cost2)
            return (diffSum * cost1) % MOD;
        // 情况三
        long long ans = LLONG_MAX;
        // 从 maxNum 到 2 * maxNum 枚举目标数
        for (int i = maxNum; i <= 2 * maxNum; i++)
        {
            long long cost = 0LL;
            if (maxDiff > diffSum - maxDiff)
            {
                // 结论一
                cost += (diffSum - maxDiff) * cost2;
                cost += (maxDiff - (diffSum - maxDiff)) * cost1;
            }
            else
            {
                // 结论二
                cost = (diffSum / 2) * cost2;
                if (diffSum % 2 == 1)
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
// @lc code=end
