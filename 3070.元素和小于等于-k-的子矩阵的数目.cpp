/*
 * @lc app=leetcode.cn id=3070 lang=cpp
 *
 * [3070] 元素和小于等于 k 的子矩阵的数目
 */

// @lc code=start

// 二维前缀和

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        if (grid.empty())
            return 0;
        if (grid[0][0] > k)
            return 0;

        int m = grid.size(), n = m ? grid[0].size() : 0;
        // sum[i + 1][j + 1] 表示以 grid[0][0] 为左上角，
        // 以 grid[i][j] 为右下角的子矩阵的元素和 
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
                if (sum[i + 1][j + 1] <= k)
                    count++;
            }
        return count;
    }
};
// @lc code=end
