/*
 * @lc app=leetcode.cn id=3127 lang=cpp
 *
 * [3127] 构造相同颜色的正方形
 */

// @lc code=start
class Solution
{
public:
    bool canMakeSquare(vector<vector<char>> &grid)
    {
        // 判断以 (row, col) 为左上角的 2*2 的正方形是否满足要求
        auto check = [&](int row, int col) -> bool
        {
            int cntB = 0, cntW = 0;
            for (int i = row; i <= row + 1; i++)
                for (int j = col; j <= col + 1; j++)
                {
                    if (grid[i][j] == 'B')
                        cntB++;
                    else
                        cntW++;
                }
            return cntB >= 3 || cntW >= 3;
        };
        // 对于 3*3 的矩阵，只需要考虑 4 种情况
        return check(0, 0) || check(0, 1) || check(1, 0) || check(1, 1);
    }
};
// @lc code=end
