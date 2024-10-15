/*
 * @lc app=leetcode.cn id=3317 lang=cpp
 *
 * [3317] 安排活动的方案数
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int numberOfWays(int n, int x, int y)
    {
        // dp[i][j] 表示前 i 个人表演 j 个节目的方案数
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
        // 初始化
        dp[0][0] = 1;
        // 状态转移
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= x; j++)
            {
                // 第 i 个人的节目在前面已经表演过了,那么有 j 个老节目可以选
                dp[i][j] = (dp[i][j] + dp[i - 1][j] * j) % MOD;
                // 第 i 个人要表演个新节目，那么有 (x−j+1) 个新节目可以选
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (x - j + 1)) % MOD;
            }
        long long ans = 0LL, mult = 1LL;
        for (int j = 1; j <= x; j++)
        {
            mult = (mult * y) % MOD;
            // 一共表演了 j 种节目，有 y^j 种打分方案
            ans = (ans + dp[n][j] * mult) % MOD;
        }
        return ans;
    }
};
// @lc code=end
