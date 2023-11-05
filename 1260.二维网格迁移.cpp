/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        vector<int> arr(m * n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                arr[(i * n + j + k) % (m * n)] = grid[i][j];
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = arr[i * n + j];
        return ans;
    }
};
// @lc code=end
