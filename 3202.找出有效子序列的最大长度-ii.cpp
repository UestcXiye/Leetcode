/*
 * @lc app=leetcode.cn id=3202 lang=cpp
 *
 * [3202] 找出有效子序列的最大长度 II
 */

// @lc code=start
class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        // dp[i][j]: 以 nums[i] 结尾模 k 后值为 j 的最长子序列的长度
        vector<vector<int>> dp(n, vector<int>(k, 1));

        int ans = 1;
        // 状态转移
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                dp[i][(nums[i] + nums[j]) % k] = dp[j][(nums[i] + nums[j]) % k] + 1;
                ans = max(ans, dp[i][(nums[i] + nums[j]) % k]);
            }
        return ans;
    }
};
// @lc code=end
