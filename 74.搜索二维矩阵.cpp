/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start

// 暴力

// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         if (matrix.empty())
//             return false;
//         int m = matrix.size(), n = m ? matrix[0].size() : 0;
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (matrix[i][j] == target)
//                     return true;
//         return false;
//     }
// };

// 一次二分查找

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int left = 0, right = m * n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int r = mid / n, c = mid % n;
            if (matrix[r][c] > target)
                right = mid - 1;
            else if (matrix[r][c] < target)
                left = mid + 1;
            else
                return true;
        }
        return false;
    }
};
// @lc code=end
