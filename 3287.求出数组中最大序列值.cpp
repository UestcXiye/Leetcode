/*
 * @lc app=leetcode.cn id=3287 lang=cpp
 *
 * [3287] 求出数组中最大序列值
 */

// @lc code=start
class Solution
{
private:
    static const int MX = 1 << 7;

public:
    int maxValue(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<array<bool, MX>> pre(k + 1);
        vector<array<bool, MX>> suf(n - k + 1);
        vector<array<bool, MX>> dp(k + 1);
        dp[0][0] = true;
        // 状态转移
        for (int i = n - 1; i >= k; i--)
        {
            int v = nums[i];
            for (int j = min(k - 1, n - 1 - i); j >= 0; j--)
            {
                for (int x = 0; x < MX; x++)
                    if (dp[j][x])
                        dp[j + 1][x | v] = true;
            }
            if (i <= n - k)
                suf[i] = dp[k];
        }
        int ans = 0;

        pre[0][0] = true;
        for (int i = 0; i < n - k; i++)
        {
            int v = nums[i];
            for (int j = min(k - 1, i); j >= 0; j--)
                for (int x = 0; x < MX; x++)
                    if (pre[j][x])
                        pre[j + 1][x | v] = true;
            if (i < k - 1)
                continue;
            for (int x = 0; x < MX; x++)
                if (pre[k][x])
                    for (int y = 0; y < MX; y++)
                        if (suf[i + 1][y])
                            ans = max(ans, x ^ y);
        }
        return ans;
    }
};
// @lc code=end
