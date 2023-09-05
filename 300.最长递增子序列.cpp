/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// class Solution
// {
// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         // 特判
//         if (nums.size() == 1)
//             return 1;
//         int n = nums.size(), maxLength = 0;
//         // 状态数组，并初始化
//         vector<int> dp(n, 1);
//         // 状态转移
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < i; j++)
//             {
//                 if (nums[i] > nums[j])
//                     dp[i] = max(dp[i], dp[j] + 1); // 状态转移方程
//                 maxLength = max(maxLength, dp[i]);
//             }
//         return maxLength;
//     }
// };

// 二分查找
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // 特判
        if (nums.size() == 1)
            return 1;
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (dp.back() < nums[i])
                dp.push_back(nums[i]);
            else
            {
                auto iter = lower_bound(dp.begin(), dp.end(), nums[i]);
                *iter = nums[i];
            }
        }
        return dp.size();
    }
};
// @lc code=end
