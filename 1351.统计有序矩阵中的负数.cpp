/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 *
 * [1351] 统计有序矩阵中的负数
 */

// @lc code=start
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        // 特判
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int count = 0;
        for (int i = 0, j = n - 1; i < m && j >= 0;)
        {
            if (grid[i][j] >= 0)
                i++;
            else
            {
                count += m - i;
                j--;
            }
        }
        return count;
    }
};
// @lc code=end
