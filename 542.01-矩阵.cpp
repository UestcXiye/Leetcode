/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // 特判
        if (mat.empty())
            return {};
        int m = mat.size(), n = m ? mat[0].size() : 0;
        // 状态矩阵
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));
        // 初始化状态矩阵
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
        // 状态转移，从左上更新到右下，注意边界
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        // 状态转移，从右下更新到左上，注意边界
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
            {
                if (i < m - 1)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                if (j < n - 1)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        return dp;
    }
};
// @lc code=end
