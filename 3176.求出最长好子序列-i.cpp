/*
 * @lc app=leetcode.cn id=3176 lang=cpp
 *
 * [3176] 求出最长好子序列 I
 */

// @lc code=start
class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        // 初始化
        for (int i = n - 1; i >= 0; i--)
            for (int j = n - 1; j > i; j--)
                if (nums[i] == nums[j])
                    dp[0][i] = max(dp[0][i], dp[0][j] + 1);
        // 状态转移
        for (int i = 1; i <= k; i++)
            for (int j = n - 1; j >= 0; j--)
                for (int q = n - 1; q > j; q--)
                {
                    if (nums[j] == nums[q])
                        dp[i][j] = max(dp[i][q] + 1, dp[i][j]);
                    else
                        dp[i][j] = max(dp[i - 1][q] + 1, dp[i][j]);
                }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[k][i] + 1);
        return ans;
    }
};
// @lc code=end
