/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution
{
private:
    vector<int> direction{-1, 0, 1, 0, -1};

public:
    // 主函数
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        if (heights.empty() || heights[0].empty())
            return {};
        int m = heights.size(), n = m ? heights[0].size() : 0;
        vector<vector<int>> result;
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            dfs(heights, can_reach_p, i, 0);
            dfs(heights, can_reach_a, i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(heights, can_reach_p, 0, i);
            dfs(heights, can_reach_a, m - 1, i);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (can_reach_p[i][j] && can_reach_a[i][j])
                    result.push_back(vector<int>{i, j});
        return result;
    }
    // 辅函数
    void dfs(const vector<vector<int>> &heights, vector<vector<bool>> &can_reach, int r, int c)
    {
        if (can_reach[r][c] == true)
            return;
        int m = heights.size(), n = m ? heights[0].size() : 0;
        can_reach[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int x = r + direction[i], y = c + direction[i + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && heights[r][c] <= heights[x][y])
                dfs(heights, can_reach, x, y);
        }
    }
};
// @lc code=end
