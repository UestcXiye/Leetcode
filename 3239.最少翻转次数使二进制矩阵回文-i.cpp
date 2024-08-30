/*
 * @lc app=leetcode.cn id=3239 lang=cpp
 *
 * [3239] 最少翻转次数使二进制矩阵回文 I
 */

// @lc code=start
class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        
        int diff_row = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n / 2; j++)
                diff_row += grid[i][j] != grid[i][n - 1 - j];

        int diff_col = 0;
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m / 2; i++)
                diff_col += grid[i][j] != grid[m - 1 - i][j];

        return min(diff_row, diff_col);
    }
};
// @lc code=end
