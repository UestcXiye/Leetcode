/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int ans = 0;
//         for (int i = 1; i < prices.size(); i++)
//             if (prices[i] - prices[i - 1] > 0)
//                 ans += prices[i] - prices[i - 1];
//         return ans;
//     }
// };
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
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // dp[i][0]: 第i天交易完后手里没有股票的最大利润
        // dp[i][1]: 第i天交易完后手里持有股票的最大利润
        // 初始化
        dp[1][0] = 0, dp[1][1] = -prices[0];
        // 状态转移
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};
// @lc code=end
