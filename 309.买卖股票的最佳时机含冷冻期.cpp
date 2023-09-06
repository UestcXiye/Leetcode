/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 特判
        if (prices.empty())
            return 0;
        int n = prices.size();
        // 状态数组
        vector<vector<int>> dp(n, vector<int>(3, 0));
        // dp[i][0]: 手上持有股票的最大收益
        // dp[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // dp[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        dp[0][0] = -prices[0], dp[0][1] = 0, dp[0][2] = 0; // 初始化
        for (int i = 1; i < n; i++)
        {
            // 第i-1天持有股票，或当天买入股票（不在冷冻期中）
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            // 在当天卖出了股票，在冷冻期中
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 当天没有进行任何操作，且第i-1天也未持有股票
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        // 答案为最后一天，三种状态的最大值
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};
// @lc code=end
