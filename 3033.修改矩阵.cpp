/*
 * @lc app=leetcode.cn id=3033 lang=cpp
 *
 * [3033] 修改矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};

        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        auto answer = matrix;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                // 每个值为 -1 的元素需要替换
                if (matrix[i][j] == -1)
                {
                    // 找到列最大值
                    int col_max = -1;
                    for (int k = 0; k < m; k++)
                        col_max = max(col_max, matrix[k][j]);
                    // 修改 answer 数组
                    answer[i][j] = col_max;
                }
            }

        return answer;
    }
};
// @lc code=end
