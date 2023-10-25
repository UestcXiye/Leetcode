/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] 掷骰子等于目标和的方法数
 */

// @lc code=start
class Solution
{
private:
    static const int MOD = 1e9 + 7;

public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        // 初始化
        for (int i = 1; i <= k && i <= target; i++)
            dp[1][i] = 1;
        // 动态规划
        for (int i = 2; i <= n; i++)
            for (int j = 0; j <= target; j++)
            {
                for (int x = 1; x <= k; x++)
                    if (j - x >= i - 1 && j - x <= k * (i - 1))
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
            }
        return dp[n][target];
    }
};
// @lc code=end
