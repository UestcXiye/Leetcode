/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size(), n = m ? mat[0].size() : 0;
        // 特判
        if (m == r && n == c)
            return mat;
        if (m * n != r * c)
            return mat;
        queue<int> temp;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                temp.push(mat[i][j]);
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                ans[i][j] = temp.front();
                temp.pop();
            }
        return ans;
    }
};
// @lc code=end
