/*
 * @lc app=leetcode.cn id=2706 lang=cpp
 *
 * [2706] 购买两块巧克力
 */

// @lc code=start
class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        sort(prices.begin(), prices.end());
        int cost = prices[0] + prices[1];
        if (cost > money)
            return money;
        else
            return money - cost;
    }
};
// @lc code=end
