/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnts(mx + 1, 0);
        // 统计各点数的出现次数
        for (int &num : nums)
            cnts[num]++;
        // dp[i] 表示在 [0, nums[i]] 内能获得的最大点数
        vector<int> dp(mx + 1, 0);
        // 初始化
        dp[1] = cnts[1] * 1;
        // 状态转移
        for (int i = 2; i <= mx; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + cnts[i] * i);
        return dp[mx];
    }
};
// @lc code=end
