/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */

// @lc code=start
class Solution
{
private:
    const vector<int> dr = {0, 1, 0, -1};
    const vector<int> dc = {1, 0, -1, 0};

public:
    int surfaceArea(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int ans = 0;
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++)
                if (grid[r][c] > 0)
                {
                    ans += 2;
                    for (int k = 0; k < 4; ++k)
                    {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        int nv = 0;
                        if (0 <= nr && nr < n && 0 <= nc && nc < n)
                            nv = grid[nr][nc];
                        ans += max(grid[r][c] - nv, 0);
                    }
                }
        return ans;
    }
};
// @lc code=end
