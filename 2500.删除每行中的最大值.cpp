/*
 * @lc app=leetcode.cn id=2500 lang=cpp
 *
 * [2500] 删除每行中的最大值
 */

// @lc code=start
class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
            sort(grid[i].begin(), grid[i].end());
        int ans = 0;
        for (int col = 0; col < n; col++)
        {
            int maxOfCol = 0;
            for (int row = 0; row < m; row++)
                maxOfCol = max(maxOfCol, grid[row][col]);
            ans += maxOfCol;
        }
        return ans;
    }
};
// @lc code=end
