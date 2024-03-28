/*
 * @lc app=leetcode.cn id=1997 lang=cpp
 *
 * [1997] 访问完所有房间的第一天
 */

// @lc code=start
class Solution
{
private:
    const int mod = 1e9 + 7;

public:
    int firstDayBeenInAllRooms(vector<int> &nextVisit)
    {
        int n = nextVisit.size();
        // dp[i]: 从 0 号房间出发首次到 i+1 花费的天数
        vector<int> dp(n);
        // 初始化
        dp[0] = 2; // 初始化原地待一天 + 访问下一个房间一天
        // 状态转移
        for (int i = 1; i < n; i++)
        {
            int to = nextVisit[i];
            dp[i] = 2 + dp[i - 1];

            if (to != 0)
            {
                dp[i] = (dp[i] - dp[to - 1] + mod) % mod; // 避免负数
            }
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        }
        return dp[n - 2]; // 题目保证n >= 2
    }
};
// @lc code=end
