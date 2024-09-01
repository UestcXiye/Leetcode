/*
 * @lc app=leetcode.cn id=3251 lang=cpp
 *
 * [3251] 单调数组对的数目 II
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int countOfPairs(vector<int> &nums)
    {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<vector<long long>> dp(n, vector<long long>(m + 1));
        vector<long long> preSum(m + 1);

        fill(dp[0].begin(), dp[0].begin() + nums[0] + 1, 1);
        for (int i = 1; i < n; i++)
        {
            partial_sum(dp[i - 1].begin(), dp[i - 1].end(), preSum.begin()); // dp[i-1] 的前缀和
            for (int j = 0; j <= nums[i]; j++)
            {
                int max_k = j + min(nums[i - 1] - nums[i], 0);
                dp[i][j] = max_k >= 0 ? preSum[max_k] % MOD : 0;
            }
        }

        return accumulate(dp[n - 1].begin(), dp[n - 1].begin() + nums[n - 1] + 1, 0LL) % MOD;
    }
};
// @lc code=end
