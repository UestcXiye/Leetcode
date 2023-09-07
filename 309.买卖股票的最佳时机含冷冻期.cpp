/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         // 特判
//         if (prices.empty())
//             return 0;
//         int n = prices.size();
//         // 状态数组
//         vector<vector<int>> dp(n, vector<int>(3, 0));
//         // dp[i][0]: 手上持有股票的最大收益
//         // dp[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
//         // dp[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
//         dp[0][0] = -prices[0], dp[0][1] = 0, dp[0][2] = 0; // 初始化
//         for (int i = 1; i < n; i++)
//         {
//             // 第i-1天持有股票，或当天买入股票（不在冷冻期中）
//             dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
//             // 在当天卖出了股票，在冷冻期中
//             dp[i][1] = dp[i - 1][0] + prices[i];
//             // 当天没有进行任何操作，且第i-1天也未持有股票
//             dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
//         }
//         // 答案为最后一天，三种状态的最大值
//         return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
//     }
// };

// 双数组DP
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         // 特判
//         if (prices.empty())
//             return 0;
//         int n = prices.size();
//         // 状态数组
//         vector<int> hold(n + 1, 0);   // 第i天持有股票的最大收益
//         vector<int> unhold(n + 1, 0); // 第i天不持有股票的最大收益
//         // 初始化
//         hold[1] = -prices[0];
//         // 状态转移
//         for (int i = 2; i <= n; i++)
//         {
//             // 情况一：昨天就持有股票，今天休息
//             // 情况二：前天卖了股票，今天买了股票
//             hold[i] = max(hold[i - 1], unhold[i - 2] - prices[i - 1]);
//             // 情况一：昨天也没有持有股票，今天休息
//             // 情况二：昨天持有股票，今天卖了股票
//             unhold[i] = max(unhold[i - 1], hold[i - 1] + prices[i - 1]);
//         }
//         return max(hold[n], unhold[n]);
//     }
// };

// 状态机
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         // 特判
//         if (prices.empty())
//             return 0;
//         int n = prices.size();
//         // 状态数组
//         vector<int> buy(n + 1, 0), sell(n + 1, 0);
//         // buy[i]: 第i天买入股票的最大收益
//         // sell[i]: 第i天卖出股票（进入冷静期）的最大收益
//         // s1[i]: 第i天持有股票的最大收益
//         // s2[i]: 第i天不持有股票的最大收益
//         vector<int> s1(n + 1, 0), s2(n + 1, 0);
//         // 初始化
//         s1[1] = buy[1] = -prices[0];
//         for (int i = 2; i <= n; i++)
//         {
//             buy[i] = s2[i - 1] - prices[i - 1];
//             s1[i] = max(buy[i - 1], s1[i - 1]);
//             sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i - 1];
//             s2[i] = max(s2[i - 1], sell[i - 1]);
//         }
//         return max(sell[n], s2[n]);
//     }
// };

// 状态机优化
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         // 特判
//         if (prices.empty())
//             return 0;
//         int n = prices.size();
//         // 状态数组
//         vector<int> rest(n + 1, 0);
//         // rest[i]: 第i天手中没持有股票且可以购买股票的最大收益
//         vector<int> sold(n + 1, 0);
//         // sold[i]: 第i天手中没持有股票且处于冷静期的最大收益
//         vector<int> hold(n + 1, 0);
//         // hold[i]: 第i天手中持有股票的最大收益
//         // 初始化
//         hold[1] = -prices[0];
//         // 状态转移
//         for (int i = 2; i <= n; i++)
//         {
//             int preSold = sold[i - 1], preHold = hold[i - 1];
//             hold[i] = max(preHold, rest[i - 1] - prices[i - 1]);
//             sold[i] = preHold + prices[i - 1];
//             rest[i] = max(rest[i - 1], preSold);
//         }
//         return max(rest[n], sold[n]);
//     }
// };

// 状态机优化-空间优化
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 特判
        if (prices.empty())
            return 0;
        // 对于每一天有三种状态:
        // rest: 手中没持有，可以买
        // hold: 手中持有，可以卖
        // sold: 手中没持有，买不了
        int rest = 0, sold = 0, hold = INT_MIN;
        for (int &price : prices)
        {
            int preSold = sold, preHold = hold;
            hold = max(preHold, rest - price);
            sold = preHold + price;
            rest = max(rest, preSold);
        }
        return max(rest, sold);
    }
};
// @lc code=end
