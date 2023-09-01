/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        if (mat.empty())
            return 0;
        int n = mat.size();
        if (n == 1)
            return mat[0][0];
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j || i + j == n - 1)
                    sum += mat[i][j];
            }
        return sum;
    }
};
// @lc code=end
