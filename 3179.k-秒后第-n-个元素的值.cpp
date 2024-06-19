/*
 * @lc app=leetcode.cn id=3179 lang=cpp
 *
 * [3179] K 秒后第 N 个元素的值
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int valueAfterKSeconds(int n, int k)
    {
        int a[n];
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0 || i == 0)
                    a[j] = 1;
                else
                    a[j] = (a[j] + a[j - 1]) % MOD;
            }
        }
        return a[n - 1];
    }
};
// @lc code=end
