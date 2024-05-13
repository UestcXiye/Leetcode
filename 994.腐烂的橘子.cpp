/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution
{
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }

        if (fresh == 0)
            return 0;
        else if (q.empty())
            return -1;

        int time = 0;
        while (fresh > 0 && !q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int r = x + dx[k], c = y + dy[k];
                    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                    {
                        fresh--;
                        grid[r][c] = 2;
                        q.push({r, c});
                    }
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : time;
    }
};
// @lc code=end
