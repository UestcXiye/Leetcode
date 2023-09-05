/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        // 状态矩阵，并初始化
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;
        // 状态转移
        for (int i = 1; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], dp[i - pow(j, 2)] + 1); // 状态转移方程
        return dp[n];
    }
};
// @lc code=end
