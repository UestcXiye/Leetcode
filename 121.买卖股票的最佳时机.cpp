/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
// TLE
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         if (prices.size() <= 1)
//             return 0;
//         int n = prices.size(), ans = 0;
//         for (int i = 0; i < n; i++)
//             for (int j = i + 1; j < n; j++)
//                 ans = max(ans, prices[j] - prices[i]);
//         return ans;
//     }
// };

// 动态规划

// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         // 特判
//         if (prices.size() <= 1)
//             return 0;
//         int n = prices.size(), max_profit = 0;
//         vector<int> dp(n, 0); // 状态数组
//         dp[0] = prices[0];    // 初始化
//         // dp[i]表示截止到第i天，股票价格的最低点
//         // 状态转移
//         for (int i = 1; i < n; i++)
//         {
//             dp[i] = min(dp[i - 1], prices[i]);
//             max_profit = max(max_profit, prices[i] - dp[i]);
//         }
//         return max_profit;
//     }
// };

// 空间压缩

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 特判
        if (prices.size() <= 1)
            return 0;
        int n = prices.size(), low_price = prices[0], max_profit = 0;
        // 状态转移
        for (int i = 1; i < n; i++)
        {
            low_price = min(low_price, prices[i]);
            max_profit = max(max_profit, prices[i] - low_price);
        }
        return max_profit;
    }
};
// @lc code=end
