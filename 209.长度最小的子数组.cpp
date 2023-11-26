/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start

// 前缀和 + 二分查找

// class Solution
// {
// public:
//     int minSubArrayLen(int target, vector<int> &nums)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;
//         int n = nums.size();
//         vector<int> preSum(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//             preSum[i] = preSum[i - 1] + nums[i - 1];
//         int min_len = INT_MAX;
//         for (int i = 1; i <= n; i++)
//         {
//             int cur_target = preSum[i - 1] + target;
//             auto bound = lower_bound(preSum.begin(), preSum.end(), cur_target);
//             if (bound != preSum.end())
//                 min_len = min(min_len, static_cast<int>((bound - preSum.begin()) - (i - 1)));
//         }
//         return min_len == INT_MAX ? 0 : min_len;
//     }
// };

// 滑动窗口

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 特判
        if (nums.empty())
            return 0;
        int n = nums.size();
        int min_len = INT_MAX;
        int sum = 0, start = 0, end = 0;
        while (end < n)
        {
            sum += nums[end];
            while (sum >= target)
            {
                int len = end - start + 1;
                min_len = min(min_len, len);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
// @lc code=end
