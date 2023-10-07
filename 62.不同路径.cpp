/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start

// 动态规划

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // 特判
        if (m == 1 || n == 1)
            return 1;
        // 状态矩阵
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[i][j]: 从起始点到达 [i, j] 的路径数
        // 初始化
        for (int i = 1; i <= m; i++)
            dp[i][1] = 1;
        for (int j = 1; j <= n; j++)
            dp[1][j] = 1;
        // 状态转移
        for (int i = 2; i <= m; i++)
            for (int j = 2; j <= n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // 状态转移方程
        return dp[m][n];
    }
};
// @lc code=end
