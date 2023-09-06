/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        // 特判
        if (k == 0 || prices.size() == 0)
            return 0;
        int n = prices.size();
        // 状态数组
        vector<int> buy(k, -prices[0]);
        // buy[j]: 在第j次买入时的最大收益
        // sell[j]: 在第j次卖出时的最大收益
        vector<int> sell(k, 0);
        // 状态转移
        for (int i = 1; i < n; i++)
        {
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for (int j = 1; j < k; j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k - 1];
    }
};
// @lc code=end
