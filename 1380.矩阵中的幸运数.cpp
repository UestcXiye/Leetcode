/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int elem = matrix[i][j];
                vector<int> row(matrix[i].begin(), matrix[i].end());
                vector<int> col;
                for (int k = 0; k < m; k++)
                    col.push_back(matrix[k][j]);
                sort(row.begin(), row.end());
                sort(col.begin(), col.end(), greater<int>());
                if (elem == row[0] && elem == col[0])
                    ans.push_back(elem);
            }
        }
        return ans;
    }
};
// @lc code=end
