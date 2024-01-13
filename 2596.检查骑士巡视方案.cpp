/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 *
 * [2596] 检查骑士巡视方案
 */

// @lc code=start

// 广度优先搜索

// class Solution
// {
// private:
//     const int dx[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
//     const int dy[8] = {-1, 1, -2, 2, -1, 1, -2, 2};

// public:
//     bool checkValidGrid(vector<vector<int>> &grid)
//     {
//         // 特判
//         if (grid[0][0] != 0)
//             return false;

//         int n = grid.size();
//         // 骑士会从棋盘的左上角出发
//         int x = 0, y = 0;
//         int index = 0, steps = n * n;
//         for (index = 1; index < steps; index++)
//         {
//             bool flag = false;
//             for (int i = 0; i < 8; i++)
//             {
//                 int r = x + dx[i], c = y + dy[i];
//                 if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == index)
//                 {
//                     x = r, y = c;
//                     flag = true;
//                     break;
//                 }
//             }
//             if (flag == false)
//                 return false;
//         }
//         return true;
//     }
// };

// 模拟

class Solution
{
public:
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        if (grid[0][0] != 0)
        {
            return false;
        }
        int n = grid.size();
        vector<array<int, 2>> indices(n * n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                indices[grid[i][j]] = {i, j};
        for (int i = 1; i < indices.size(); i++)
        {
            int dx = abs(indices[i][0] - indices[i - 1][0]);
            int dy = abs(indices[i][1] - indices[i - 1][1]);
            if (dx * dy != 2)
                return false;
        }
        return true;
    }
};

// @lc code=end
