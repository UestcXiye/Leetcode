/*
 * @lc app=leetcode.cn id=2369 lang=cpp
 *
 * [2369] 检查数组是否存在有效划分
 */

// @lc code=start

// 划分型 DP

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        // dp[i]: 子数组 nums[0,...,i-1] 是否存在有效划分
        vector<bool> dp(n + 1, false);
        // 初始化
        dp[0] = true;
        // 状态转移
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                dp[i + 1] = dp[i + 1] | dp[i - 1];
            if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
                dp[i + 1] = dp[i + 1] | dp[i - 2];
            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1)
                dp[i + 1] = dp[i + 1] | dp[i - 2];
        }
        return dp[n];
    }
};

// @lc code=end
