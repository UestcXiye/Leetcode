/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
// class Solution
// {
// public:
//     int rob(vector<int> &nums)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;
//         if (nums.size() == 1)
//             return nums[0];
//         // 有n个房间，分成2种情况：
//         // 1. 偷编号为0,1,2,...,n-2的n-1个房间
//         vector<int> nums1(nums.begin(), nums.end() - 1);
//         // 2. 偷编号为1,2,3,...,n-1的n-1个房间
//         vector<int> nums2(nums.begin() + 1, nums.end());
//         // 问题转化为198.打家劫舍的问题，返回两种情况偷窃到的最高金额
//         return max(rob1(nums1), rob1(nums2));
//     }
//     // 198.打家劫舍原函数
//     int rob1(vector<int> &nums)
//     {
//         if (nums.empty())
//             return 0;
//         int n = nums.size();
//         vector<int> dp(n + 1, 0);
//         dp[0] = 0, dp[1] = nums[0];
//         for (int i = 2; i <= n; i++)
//             dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
//         return dp[n];
//     }
// };

// class Solution
// {
// public:
//     int rob(vector<int> &nums)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;
//         if (nums.size() == 1)
//             return nums[0];
//         int n = nums.size();
//         // 状态数组，并初始化
//         vector<int> dp1(n, 0), dp2(n, 0);
//         // dp1: 偷编号为0,1,2,...,n-2的n-1个房间
//         // dp2: 偷编号为1,2,3,...,n-1的n-1个房间
//         dp1[0] = nums[0];
//         dp1[1] = max(nums[1], nums[0]);
//         dp2[1] = nums[1];
//         // 状态转移
//         for (int i = 2; i < n; i++)
//         {
//             dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
//             dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
//         }
//         return max(dp1[n - 2], dp2[n - 1]);
//     }
// };

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // 特判
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        // 状态数组，并初始化
        vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
        // dp1: 偷编号为0,1,2,...,n-2的n-1个房间
        // dp2: 偷编号为1,2,3,...,n-1的n-1个房间
        dp1[1] = nums[0];
        dp2[2] = nums[1];
        // 状态转移
        for (int i = 2; i <= n; i++)
        {
            dp1[i] = max(dp1[i - 2] + nums[i - 1], dp1[i - 1]);
            dp2[i] = max(dp2[i - 2] + nums[i - 1], dp2[i - 1]);
        }
        return max(dp1[n - 1], dp2[n]);
    }
};
// @lc code=end
