/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution
{
private:
    vector<int> direction{-1, 0, 1, 0, -1};

public:
    // 主函数
    int shortestBridge(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        queue<pair<int, int>> points;
        // dfs寻找第一个岛屿，并把1全部赋值为2
        bool flipped = false;
        for (int i = 0; i < m; i++)
        {
            if (flipped)
                break;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }
        // bfs寻找第二个岛屿，并把过程中经过的0赋值为2
        int level = 0;
        while (!points.empty())
        {
            level++;
            int n_points = points.size();
            while (n_points--)
            {
                auto [r, c] = points.front();
                grid[r][c] = 2;
                points.pop();
                for (int k = 0; k < 4; k++)
                {
                    int x = r + direction[k], y = c + direction[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n)
                    {
                        if (grid[x][y] == 2)
                            continue;
                        if (grid[x][y] == 1)
                            return level;
                        points.push(pair<int, int>{x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }
    // 辅函数
    void dfs(queue<pair<int, int>> &points, vector<vector<int>> &grid, int m, int n, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 2)
            return;
        if (grid[i][j] == 0)
        {
            points.push(pair<int, int>{i, j});
            return;
        }
        grid[i][j] = 2;
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i, j - 1);
        dfs(points, grid, m, n, i, j + 1);
    }
};
// @lc code=end
