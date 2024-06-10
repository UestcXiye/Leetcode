/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = m ? mat[0].size() : 0;
        // 一共有 m + n - 1 条对角线
        int lines = m + n - 1;
        vector<int> ans;
        for (int i = 0; i < lines; i++)
        {
            if (i % 2 == 0)
            { // ↗
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - m + 1;
                while (x >= 0 && y < n)
                {
                    ans.push_back(mat[x][y]);
                    x--, y++;
                }
            }
            else
            { // ↙
                int x = i < n ? 0 : i - n + 1;
                int y = i < n ? i : n - 1;
                while (x < m && y >= 0)
                {
                    ans.push_back(mat[x][y]);
                    x++, y--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
