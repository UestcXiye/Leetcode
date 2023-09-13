/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start

// 暴力
// Time Limit Exceeded

// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         // 特判
//         if (matrix.empty())
//             return false;
//         int m = matrix.size(), n = matrix[0].size();
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (matrix[i][j] == target)
//                     return true;
//         return false;
//     }
// };

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // 特判
        if (matrix.empty())
            return false;
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int i = m - 1, j = 0;
        // 利用矩阵的特性，从左下角出发遍历
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
};
// @lc code=end
