/*
 * @lc app=leetcode.cn id=2319 lang=cpp
 *
 * [2319] 判断矩阵是否是一个 X 矩阵
 */

// @lc code=start
class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j || i + j + 1 == n)
                {
                    if (grid[i][j] == 0)
                        return false;
                }
                else
                {
                    if (grid[i][j] != 0)
                        return false;
                }
            }
        return true;
    }
};
// @lc code=end
