/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        // 特判
        if (amount < 0 || coins.empty())
            return 0;

        // dp[i]: 总金额为 i 的硬币组合数
        vector<int> dp(amount + 1, 0);
        // 初始化
        dp[0] = 1;
        // 状态转移
        for (int &coin : coins)
            for (int i = coin; i <= amount; i++)
                dp[i] += dp[i - coin];

        return dp[amount];
    }
};
// @lc code=end
