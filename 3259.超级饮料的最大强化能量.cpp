/*
 * @lc app=leetcode.cn id=3259 lang=cpp
 *
 * [3259] 超级饮料的最大强化能量
 */

// @lc code=start
class Solution
{
public:
    long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB)
    {
        int n = energyDrinkA.size();
        vector<array<long long, 2>> dp(n + 2);
        // 状态转移
        for (int i = 0; i < n; i++)
        {
            dp[i + 2][0] = max(dp[i + 1][0], dp[i][1]) + energyDrinkA[i];
            dp[i + 2][1] = max(dp[i + 1][1], dp[i][0]) + energyDrinkB[i];
        }
        return max(dp[n + 1][0], dp[n + 1][1]);
    }
};
// @lc code=end
