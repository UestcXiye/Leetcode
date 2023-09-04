/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // 特判
        if (grid.empty())
            return 0;
        int m = grid.size(), n = m ? grid[0].size() : 0;
        // 状态矩阵
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化状态矩阵的第一行和第一列
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        // 状态转移
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]; // 状态转移方程
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
