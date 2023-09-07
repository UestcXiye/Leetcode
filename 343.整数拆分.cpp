/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0); // 状态数组
        // dp[i]: 总和为i，拆分数的最大乘积
        dp[0] = dp[1] = 0;
        // 状态转移
        for (int i = 2; i <= n; i++)
            for (int j = 1; j < i; j++)
            {
                // 方案一：将i拆分成j和i-j的和，且i-j不再拆分成多个正整数
                // 方案二：将i拆分成j和i-j的和，且i-j继续拆分成多个正整数
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j])); // 状态转移方程
            }
        return dp[n];
    }
};
// @lc code=end
