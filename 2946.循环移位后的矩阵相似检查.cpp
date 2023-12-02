/*
 * @lc app=leetcode.cn id=2946 lang=cpp
 *
 * [2946] 循环移位后的矩阵相似检查
 */

// @lc code=start
class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        if (mat.empty())
            return false;
        int m = mat.size(), n = m ? mat[0].size() : 0;
        k = k % n;
        if (k == 0)
            return true;
        for (int i = 0; i < m; i++)
        {
            if (i % 2)
            {
                for (int j = 0; j < n; j++)
                    if (mat[i][(j + k) % n] != mat[i][j])
                        return false;
            }
            else
            {
                for (int j = 0; j < n; j++)
                    if (mat[i][(j + n - k) % n] != mat[i][j])
                        return false;
            }
        }
        return true;
    }
};
// @lc code=end
