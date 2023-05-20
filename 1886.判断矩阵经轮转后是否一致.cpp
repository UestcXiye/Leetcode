/*
 * @lc app=leetcode.cn id=1886 lang=cpp
 *
 * [1886] 判断矩阵经轮转后是否一致
 */

// @lc code=start
class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int n = target.size();
        bool type1 = true, type2 = true, type3 = true, type4 = true;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != target[i][j])
                    type1 = false;
                if (mat[i][j] != target[j][n - 1 - i])
                    type2 = false;
                if (mat[i][j] != target[n - 1 - i][n - 1 - j])
                    type3 = false;
                if (mat[i][j] != target[n - 1 - j][i])
                    type4 = false;
            }
        return type1 || type2 || type3 || type4;
    }
};
// @lc code=end
