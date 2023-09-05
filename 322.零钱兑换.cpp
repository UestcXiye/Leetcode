/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
// TLE
// class Solution
// {
// public:
//     int coinChange(vector<int> &coins, int amount)
//     {
//         if (coins.empty())
//             return -1;
//         if (amount == 0)
//             return 0;
//         int n = coins.size();
//         // 状态数组，并初始化
//         vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));
//         dp[0][0] = 0;
//         // 状态转移
//         for (int i = 1; i <= n; i++)
//         {
//             int w = coins[i - 1];
//             for (int j = 0; j <= amount; j++)
//             {
//                 for (int k = 0; k * w <= j; k++)
//                     dp[i][j] = min(dp[i][j], dp[i - 1][j - k * w] + k);
//             }
//         }
//         return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
//     }
// };

// 空间压缩
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // 特判
        if (coins.empty())
            return -1;
        if (amount == 0)
            return 0;
        int n = coins.size();
        // 状态数组，并初始化
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        // 状态转移
        for (int i = 1; i <= n; i++)
        {
            int w = coins[i - 1];
            for (int j = w; j <= amount; j++)
                dp[j] = min(dp[j], dp[j - w] + 1); // 状态转移方程
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount]; // 最后还需要判断一下
    }
};
// @lc code=end
