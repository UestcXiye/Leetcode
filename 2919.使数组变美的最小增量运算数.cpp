/*
 * @lc app=leetcode.cn id=2919 lang=cpp
 *
 * [2919] 使数组变美的最小增量运算数
 */

// @lc code=start
class Solution
{
public:
    long long minIncrementOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        // dp[i] 表示表示修改第 i 项并使前 i 项变为美丽数组的最小修改次数
        vector<long long> dp(n, 0);
        // 初始化
        for (int i = 0; i < 3; i++)
            dp[i] = max(0, k - nums[i]);
        // 状态转移
        for (int i = 3; i < n; i++)
        {
            // 状态转移方程
            dp[i] = min(dp[i - 3], min(dp[i - 2], dp[i - 1])) + max(0, k - nums[i]);
        }
        return min(dp[n - 3], min(dp[n - 2], dp[n - 1]));
    }
};
// @lc code=end
