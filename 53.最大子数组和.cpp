/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 特判
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        // 状态数组
        vector<int> dp(n + 1, 0);
        // dp[i]: 以第i个元素结尾，连续子数组的最大和
        int maxSum = INT_MIN;
        // 状态转移
        for (int i = 1; i <= n; i++)
        {
            if (dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i - 1];
            else
                dp[i] = nums[i - 1];
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

// 空间优化
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;
//         if (nums.size() == 1)
//             return nums[0];
//         int n = nums.size();
//         int pre = 0, cur = 0, maxSum = INT_MIN;
//         for (int i = 0; i < n; i++)
//         {
//             if (pre > 0)
//                 cur = pre + nums[i];
//             else
//                 cur = nums[i];
//             pre = cur;
//             maxSum = max(maxSum, cur);
//         }
//         return maxSum;
//     }
// };
// @lc code=end
