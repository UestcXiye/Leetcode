/*
 * @lc app=leetcode.cn id=3240 lang=cpp
 *
 * [3240] 最少翻转次数使二进制矩阵回文 II
 */

// @lc code=start
class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int ans = 0;
        for (int i = 0; i < m / 2; i++)
            for (int j = 0; j < n / 2; j++)
            {
                int cnt1 = grid[i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
                ans += min(cnt1, 4 - cnt1); // 全为 1 或全为 0
            }
        if (m % 2 && n % 2 && grid[m / 2][n / 2] == 1)
        {
            // 正中间的数必须是 0
            ans++;
        }

        int diff = 0, cnt1 = 0;
        if (m % 2)
        {
            // 统计正中间这一排
            for (int j = 0; j < n / 2; j++)
            {
                if (grid[m / 2][j] != grid[m / 2][n - 1 - j])
                    diff++;
                else
                    cnt1 += grid[m / 2][j] * 2;
            }
        }
        if (n % 2)
        {
            // 统计正中间这一列
            for (int i = 0; i < m / 2; i++)
            {
                if (grid[i][n / 2] != grid[m - 1 - i][n / 2])
                    diff++;
                else
                    cnt1 += grid[i][n / 2] * 2;
            }
        }
        if (cnt1 % 4 == 0)
        {
            // 把这 diff 对数全部变成 0
            ans += diff;
        }
        else
        {
            if (diff)
            {
                // 把一对数都变成 1，其余全变成 0，要翻转 diff 个数
                ans += diff;
            }
            else
            {
                // 把两个 1 翻转为 0
                ans += 2;
            }
        }
        return ans;
    }
};
// @lc code=end
