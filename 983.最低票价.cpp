/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1);
        unordered_set<int> hashSet(days.begin(), days.end());
        // 初始化
        dp[0] = 0;
        // 状态转移
        for (int i = 1; i <= lastDay; i++)
        {
            if (!hashSet.contains(i))
                dp[i] = dp[i - 1];
            else
                dp[i] = min({dp[i - 1] + costs[0],
                             dp[max(i - 7, 0)] + costs[1],
                             dp[max(i - 30, 0)] + costs[2]});
        }

        return dp[lastDay];
    }
};
// @lc code=end
