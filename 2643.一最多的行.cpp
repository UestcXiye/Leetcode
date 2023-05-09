/*
 * @lc app=leetcode.cn id=2643 lang=cpp
 *
 * [2643] 一最多的行
 */

// @lc code=start
class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans = {0, 0};
        for (int i = 0; i < m; i++)
        {
            int countOne = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                    countOne++;
            }
            if (countOne > ans[1])
            {
                ans[0] = i;
                ans[1] = countOne;
            }
        }
        return ans;
    }
};
// @lc code=end
