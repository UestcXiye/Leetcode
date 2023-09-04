/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        // 特判
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int maxSide = 0; // 最大正方形的边长
        // 状态矩阵，并初始化
        vector<vector<int>> dp(m, vector<int>(n - 0));
        // 状态转移
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == '1') // not 1, it's '1', take care!
                {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
        return maxSide * maxSide;
    }
};
// @lc code=end
