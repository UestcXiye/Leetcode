/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start
class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (auto &index : indices)
        {
            for (int i = 0; i < n; i++)
                matrix[index[0]][i]++;
            for (int i = 0; i < m; i++)
                matrix[i][index[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] % 2)
                    ans++;
        return ans;
    }
};
// @lc code=end
