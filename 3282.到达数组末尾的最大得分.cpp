/*
 * @lc app=leetcode.cn id=3282 lang=cpp
 *
 * [3282] 到达数组末尾的最大得分
 */

// @lc code=start
class Solution
{
public:
    long long findMaximumScore(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0LL;
        int n = nums.size();
        vector<long long> dp(n);
        dp[0] = 0;
        int maxIndex = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[maxIndex] + 1LL * (i - maxIndex) * nums[maxIndex];
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }
        return dp[n - 1];
    }
};
// @lc code=end
