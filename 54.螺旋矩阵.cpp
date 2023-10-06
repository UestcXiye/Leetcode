/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start

// 模拟

// class Solution
// {
// private:
//     // 向右、向下、向左、向上
//     vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// public:
//     vector<int> spiralOrder(vector<vector<int>> &matrix)
//     {
//         // 特判
//         if (matrix.empty())
//             return {};
//         int m = matrix.size(), n = matrix[0].size();
//         vector<int> ans(m * n, 0);
//         vector<vector<bool>> visited(n, vector<bool>(n, false));
//         int r = 0, c = 0;
//         int directionIndex = 0;
//         for (int i = 0; i < m * n; i++)
//         {
//             ans[i] = matrix[r][c];
//             visited[r][c] = true;
//             int nextRow = r + directions[directionIndex][0], nextColumn = c + directions[directionIndex][1];
//             // 遇到边界，转向
//             if (nextRow < 0 || nextRow >= m || nextColumn < 0 || nextColumn >= n || visited[nextRow][nextColumn])
//                 directionIndex = (directionIndex + 1) % 4;
//             r += directions[directionIndex][0];
//             c += directions[directionIndex][1];
//         }
//         return
//     }
// };

// 按层模拟

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 特判
        if (matrix.empty())
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n, 0);
        int index = 0;
        // 边界标记
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        while (index < m * n)
        {
            // 向右
            for (int i = left; i <= right && index < m * n; i++)
                ans[index++] = matrix[top][i];
            top += 1;
            // 向下
            for (int i = top; i <= bottom && index < m * n; i++)
                ans[index++] = matrix[i][right];
            right -= 1;
            // 向左
            for (int i = right; i >= left && index < m * n; i--)
                ans[index++] = matrix[bottom][i];
            bottom -= 1;
            // 向上
            for (int i = bottom; i >= top && index < m * n; i--)
                ans[index++] = matrix[i][left];
            left++;
        }
        return ans;
    }
};

// @lc code=end
