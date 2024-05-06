/*
 * @lc app=leetcode.cn id=3128 lang=cpp
 *
 * [3128] 直角三角形
 */

// @lc code=start
class Solution
{
public:
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        // 每行 1 的个数
        vector<int> rows(m, 0);
        for (int i = 0; i < m; i++)
        {
            int row = 0;
            for (int j = 0; j < n; j++)
                row += grid[i][j];
            rows[i] = row;
        }
        // 每列 1 的个数
        vector<int> cols(n, 0);
        for (int j = 0; j < n; j++)
        {
            int col = 0;
            for (int i = 0; i < m; i++)
                col += grid[i][j];
            cols[j] = col;
        }
        long long ans = 0LL;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                {
                    // 直角顶点为 (i,j) 的直角三角形有 (rows[i] - 1) * (cols[j] - 1) 个
                    ans += (rows[i] - 1) * (cols[j] - 1);
                }
        return ans;
    }
};
// @lc code=end
