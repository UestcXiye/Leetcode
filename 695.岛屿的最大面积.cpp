/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
// DFS, 使用栈的写法
// class Solution
// {
// private:
//     vector<int> direction{-1, 0, 1, 0, -1};

// public:
//     int maxAreaOfIsland(vector<vector<int>> &grid)
//     {
//         int m = grid.size(), n = m ? grid[0].size() : 0;
//         int local_area, area = 0;
//         int x, y;
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (grid[i][j] == 1)
//                 {
//                     local_area = 1;
//                     grid[i][j] = 0;
//                     stack<pair<int, int>> island;
//                     island.push({i, j});
//                     while (!island.empty())
//                     {
//                         auto [r, c] = island.top();
//                         island.pop();
//                         for (int k = 0; k < 4; k++)
//                         {
//                             x = r + direction[k], y = c + direction[k + 1];
//                             if (x >= 0 && x < m &&
//                                 y >= 0 && y < n && grid[x][y] == 1)
//                             {
//                                 grid[x][y] = 0;
//                                 local_area++;
//                                 island.push({x, y});
//                             }
//                         }
//                     }
//                     area = max(area, local_area);
//                 }
//         return area;
//     }
// };

// DFS, 第一种递归写法
// class Solution
// {
// private:
//     vector<int> direction{-1, 0, 1, 0, -1};

// public:
//     // 主函数
//     int maxAreaOfIsland(vector<vector<int>> &grid)
//     {
//         if (grid.empty() || grid[0].empty())
//             return 0;
//         int m = grid.size(), n = m ? grid[0].size() : 0;
//         int max_area = 0;
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (grid[i][j] == 1)
//                     max_area = max(max_area, dfs(grid, i, j));
//         return max_area;
//     }
//     // 辅函数1: 先判定是否越界，只有在合法的情况下才进行下一步搜索（即判断放在调用递归函数前）
//     int dfs(vector<vector<int>> &grid, int r, int c)
//     {
//         if (grid[r][c] == 0)
//             return 0;
//         int m = grid.size(), n = m ? grid[0].size() : 0;
//         int area = 1;
//         grid[r][c] = 0;
//         for (int k = 0; k < 4; k++)
//         {
//             int x = r + direction[k], y = c + direction[k + 1];
//             if (x >= 0 && x < m && y >= 0 && y < n)
//                 area += dfs(grid, x, y);
//         }
//         return area;
//     }
// };

// DFS, 第二种递归写法
class Solution
{
public:
    // 主函数
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int max_area = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                max_area = max(max_area, dfs(grid, i, j));
        return max_area;
    }
    // 辅函数2: 先进行下一步搜索，待下一步搜索开始时再判断是否合法（即判断放在辅函数第一行）
    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }
};
// @lc code=end
