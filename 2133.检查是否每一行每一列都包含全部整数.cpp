/*
 * @lc app=leetcode.cn id=2133 lang=cpp
 *
 * [2133] 检查是否每一行每一列都包含全部整数
 */

// @lc code=start
class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> uset;
            for (int j = 0; j < n; j++)
            {
                uset.insert(matrix[i][j]);
            }
            for (int k = 1; k <= n; k++)
                if (!uset.count(k))
                    return false;
        }
        for (int j = 0; j < n; j++)
        {
            unordered_set<int> uset;
            for (int i = 0; i < n; i++)
            {
                uset.insert(matrix[i][j]);
            }
            for (int k = 1; k <= n; k++)
                if (!uset.count(k))
                    return false;
        }
        return true;
    }
};
// @lc code=end
