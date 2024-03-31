/*
 * @lc app=leetcode.cn id=3082 lang=cpp
 *
 * [3082] 求出所有子序列的能量和
 */

// @lc code=start
class Solution
{
private:
    const int mod = 1e9 + 7;

public:
    int sumOfPower(vector<int> &nums, int k)
    {
        int n = nums.size();
        // dp[i][j][c]: 前 i 个物品，所选物品体积和是 j，选了 c 个物品的方案数
        int dp[n + 1][k + 1][n + 1];
        // 初始化
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++)
            dp[i][0][0] = 1;
        // 状态转移
        for (int i = 0; i < n; i++)
        {
            for (int j = k; j >= 0; j--)
            {
                for (int c = n; c > 0; c--)
                {
                    // 二维0/1背包
                    dp[i + 1][j][c] = dp[i][j][c]; // 不选
                    if (j >= nums[i])
                    {
                        // 选
                        dp[i + 1][j][c] = (dp[i + 1][j][c] + dp[i][j - nums[i]][c - 1]) % mod;
                    }
                }
            }
        }
        // 贡献法
        int ans = 0;
        long p = 1;
        for (int c = n; c >= 0; c--)
        {
            ans = (ans + dp[n][k][c] * p % mod) % mod;
            p = (p * 2) % mod;
        }
        return ans;
    }
};
// @lc code=end
