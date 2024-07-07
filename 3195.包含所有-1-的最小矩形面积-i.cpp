/*
 * @lc app=leetcode.cn id=3195 lang=cpp
 *
 * [3195] 包含所有 1 的最小矩形面积 I
 */

// @lc code=start
class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int left = n, right = 0;
        int top = m, bottom = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    left = min(left, i);
                    right = max(right, i);
                    top = min(top, j);
                    bottom = max(bottom, j);
                }
            }

        return (right - left + 1) * (bottom - top + 1);
    }
};
// @lc code=end
