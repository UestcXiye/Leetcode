/*
 * @lc app=leetcode.cn id=3071 lang=cpp
 *
 * [3071] 在矩阵上写出字母 Y 所需的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    int minimumOperationsToWriteY(vector<vector<int>> &grid)
    {
        int n = grid.size();    // n 为奇数
        vector<int> cnt1(3, 0); // 字母 Y 单元格各数字的出现次数
        vector<int> cnt2(3, 0); // 非字母 Y 单元格各数字的出现次数

        auto isY = [&](int i, int j) -> bool
        {
            if (i < 0 || i > n || j < 0 || j > n)
                return false;
            if (i == j && i <= n / 2)
                return true;
            if (i + j == n - 1 && i <= n / 2)
                return true;
            if (i >= n / 2 && j == n / 2)
                return true;
            return false;
        };

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int x = grid[i][j];
                if (isY(i, j))
                    cnt1[x]++;
                else
                    cnt2[x]++;
            }

        int max_not_change = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j)
                    max_not_change = max(max_not_change, cnt1[i] + cnt2[j]);

        return n * n - max_not_change;
    }
};
// @lc code=end
