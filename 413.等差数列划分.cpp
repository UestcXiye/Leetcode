/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        // 特判
        if (nums.size() < 3)
            return 0;
        int n = nums.size();
        vector<int> dp(n, 0); // 状态矩阵，并初始化
        // 状态转移
        for (int i = 2; i < n; i++)
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1; // 状态转移方程
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end
