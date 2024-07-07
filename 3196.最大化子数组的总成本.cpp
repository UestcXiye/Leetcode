/*
 * @lc app=leetcode.cn id=3196 lang=cpp
 *
 * [3196] 最大化子数组的总成本
 */

// @lc code=start
class Solution
{
public:
    long long maximumTotalCost(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> dp(n + 1);
        // 初始化
        dp[0] = 0;
        dp[1] = nums[0];
        // 动态规划
        for (int i = 2; i <= n; i++)
            dp[i] = max(dp[i - 1] + nums[i - 1], dp[i - 2] + nums[i - 2] - nums[i - 1]);
        return dp[n];
    }
};
// @lc code=end
