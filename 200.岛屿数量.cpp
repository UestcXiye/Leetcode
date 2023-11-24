/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start

// 深度优先搜索

// class Solution
// {
// private:
//     const int dx[4] = {-1, 0, 1, 0};
//     const int dy[4] = {0, 1, 0, -1};

// public:
//     int numIslands(vector<vector<char>> &grid)
//     {
//         if (grid.empty())
//             return 0;
//         int m = grid.size(), n = m ? grid[0].size() : 0;
//         int islands = 0;
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (grid[i][j] == '1')
//                 {
//                     islands++;
//                     dfs(grid, i, j);
//                 }
//         return islands;
//     }
//     // 辅函数 - 深度优先搜索
//     void dfs(vector<vector<char>> &grid, int r, int c)
//     {
//         if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0')
//             return;
//         grid[r][c] = '0';
//         for (int i = 0; i < 4; i++)
//         {
//             int x = dx[i], y = dy[i];
//             dfs(grid, r + x, c + y);
//         }
//     }
// };

// 广度优先搜索

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int islands = 0;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (grid[r][c] == '1')
                {
                    islands++;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty())
                    {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row - 1][col] == '1')
                        {
                            neighbors.push({row - 1, col});
                            grid[row - 1][col] = '0';
                        }
                        if (row + 1 < m && grid[row + 1][col] == '1')
                        {
                            neighbors.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1')
                        {
                            neighbors.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                        if (col + 1 < n && grid[row][col + 1] == '1')
                        {
                            neighbors.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                }
        return islands;
    }
};
// @lc code=end
