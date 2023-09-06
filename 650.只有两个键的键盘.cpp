/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution
{
public:
    int minSteps(int n)
    {
        // 特判
        if (n == 1)
            return 0;
        // 状态矩阵，并初始化
        vector<int> dp(n + 1, 0);
        // dp[i]: 延展到长度i的最少操作次数
        for (int i = 2; i <= n; i++)
            dp[i] = i;
        // 状态转移
        for (int i = 2; i <= n; i++)
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    // 方案一：从dp[j]开始，复制1次，粘贴i/j+1次
                    // 方案二：从dp[i/j]，复制1次，粘贴j-1次
                    dp[i] = min(dp[i], min(dp[j] + i / j, dp[i / j] + j)); // 状态转移方程
                }
            }
        return dp[n];
    }
};
// @lc code=end
