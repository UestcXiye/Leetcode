/*
 * @lc app=leetcode.cn id=2830 lang=cpp
 *
 * [2830] 销售利润最大化
 */

// @lc code=start
class Solution
{
public:
    int maximizeTheProfit(int n, vector<vector<int>> &offers)
    {
        int m = offers.size();
        // 对购买请求按照 end 值从小到大排序
        sort(offers.begin(), offers.end(), [](vector<int> &o1, vector<int> &o2)
             { return o1[1] < o2[1]; });

        // dp[i + 1] 表示从前往后卖到编号为 i 的房子时，总的最大获利
        vector<int> dp(n + 1, 0);

        int index = 0;
        // 状态转移
        for (int i = 0; i < n; i++)
        {
            // 不卖编号为 i 的房子
            dp[i + 1] = dp[i];
            // 卖编号为 i 的房子，选获利最多的方案
            while (index < m && i == offers[index][1])
            {
                dp[i + 1] = max(dp[i + 1], offers[index][2] + dp[offers[index][0]]);
                index++;
            }
        }

        return dp[n];
    }
};
// @lc code=end
