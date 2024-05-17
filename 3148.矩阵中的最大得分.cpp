/*
 * @lc app=leetcode.cn id=3148 lang=cpp
 *
 * [3148] 矩阵中的最大得分
 */

// @lc code=start
class Solution
{
public:
    int maxScore(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        // dp[i][j] 表示以 (i,j) 为终点，起点的最小值
        int dp[m][n];
        memset(dp, INT_MAX, sizeof(dp));
        int ans = INT_MIN;
        // 状态转移
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int minGrid = INT_MAX;
                if (i > 0)
                    minGrid = min(minGrid, dp[i - 1][j]);
                if (j > 0)
                    minGrid = min(minGrid, dp[i][j - 1]);
                ans = max(ans, grid[i][j] - minGrid);
                dp[i][j] = min(grid[i][j], minGrid);
            }
        return ans;
    }
};
// @lc code=end
