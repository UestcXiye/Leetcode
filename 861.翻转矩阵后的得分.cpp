/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */

// @lc code=start
class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        // 按行反转
        for (int i = 0; i < m; i++)
            if (grid[i][0] == 0)
                for (int j = 0; j < n; j++)
                    grid[i][j] = grid[i][j] ? 0 : 1;
        // 按列反转
        for (int j = 1; j < n; j++)
        {
            int cntZero = 0;
            for (int i = 0; i < m; i++)
                if (grid[i][j] == 0)
                    cntZero++;
            if (cntZero > m - cntZero)
                for (int i = 0; i < m; i++)
                    grid[i][j] = grid[i][j] ? 0 : 1;
        }
        // 求和
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            int num = 0, mult = 1;
            for (int j = n - 1; j >= 0; j--)
            {
                num += grid[i][j] * mult;
                mult *= 2;
            }
            sum += num;
        }
        return sum;
    }
};
// @lc code=end
