/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start

// 动态规划

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // 特判
        if (obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size(), n = m ? obstacleGrid[0].size() : 0;
        // 状态矩阵
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[i][j]: 从起始点到达 [i, j] 的路径数
        // 初始化
        for (int i = 1; i <= m; i++)
        {
            if (obstacleGrid[i - 1][0] == 0)
                dp[i][1] = 1;
            else
                break;
        }
        for (int j = 1; j <= n; j++)
        {
            if (obstacleGrid[0][j - 1] == 0)
                dp[1][j] = 1;
            else
                break;
        }
        // 状态转移
        for (int i = 2; i <= m; i++)
            for (int j = 2; j <= n; j++)
            {
                if (obstacleGrid[i - 1][j - 1] == 1)
                    dp[i][j] = 0;
                else
                {
                    // 状态转移方程
                    if (obstacleGrid[i - 2][j - 1] == 1) // 上面有障碍物
                        dp[i][j] = dp[i][j - 1];
                    if (obstacleGrid[i - 1][j - 2] == 1) // 左边有障碍物
                        dp[i][j] = dp[i - 1][j];
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        return dp[m][n];
    }
};
// @lc code=end
