/*
 * @lc app=leetcode.cn id=3142 lang=cpp
 *
 * [3142] 判断矩阵是否满足条件
 */

// @lc code=start
class Solution
{
public:
    bool satisfiesConditions(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                if (grid[i][j] == grid[i][j - 1])
                    return false;
        for (int j = 0; j < n; j++)
            for (int i = 1; i < m; i++)
                if (grid[i][j] != grid[i - 1][j])
                    return false;
        return true;
    }
};
// @lc code=end
