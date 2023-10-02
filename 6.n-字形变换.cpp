/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

// @lc code=start

// 模拟

// class Solution
// {
// public:
//     string convert(string s, int numRows)
//     {
//         if (numRows == 1 || numRows >= s.size())
//             return s;
//         int n = s.size(), r = numRows;
//         // Z字形变换的周期 t=r+r−2=2*r-2，每个周期占用矩阵的 1+r-2=r-1 列
//         int t = 2 * r - 2;
//         // 矩阵的列数 c
//         int c = ceil(n * 1.0 / t) * (r - 1); // ceil：向上取整
//         // 创建一个 r 行 c 列的矩阵，初始化填充 '#'
//         vector<vector<char>> matrix(r, vector<char>(c, '#'));
//         int x = 0, y = 0;
//         for (int i = 0; i < n; i++)
//         {
//             matrix[x][y] = s[i];
//             if (i % t < r - 1)
//             {
//                 // 向下移动
//                 x++;
//             }
//             else
//             {
//                 // 向右上移动
//                 x--;
//                 y++;
//             }
//         }
//         string ans;
//         for (int i = 0; i < r; i++)
//             for (int j = 0; j < c; j++)
//                 if (matrix[i][j] != '#')
//                     ans += matrix[i][j];
//         return ans;
//     }
// };

// 标志位

class Solution
{
public:
    string convert(string s, int numRows)
    {
        // 特判
        if (numRows == 1 || numRows >= s.size())
            return s;
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char &c : s)
        {
            rows[i] += c;
            if (i == 0 || i == numRows - 1)
                flag = -flag;
            i += flag;
        }
        string ans;
        for (string &row : rows)
            ans += row;
        return ans;
    }
};
// @lc code=end
