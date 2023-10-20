/*
 * @lc app=leetcode.cn id=2874 lang=cpp
 *
 * [2874] 有序三元组中的最大值 II
 */

// @lc code=start

// 枚举k

// class Solution
// {
// public:
//     long long maximumTripletValue(vector<int> &nums)
//     {
//         int n = nums.size();
//         long long ans = INT_MIN;
//         int max_diff = 0, pre_max = 0;
//         for (int i = 0; i < n; i++)
//         {
//             ans = max(ans, (long long)max_diff * nums[i]);
//             max_diff = max(max_diff, pre_max - nums[i]);
//             pre_max = max(pre_max, nums[i]);
//         }
//         return ans >= 0 ? ans : 0;
//     }
// };

// 枚举j

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = INT_MIN;
        vector<int> pre_max(n, 0);
        pre_max[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre_max[i] = max(pre_max[i - 1], nums[i]);
        vector<int> max_suffix(n, 0);
        max_suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            max_suffix[i] = max(max_suffix[i + 1], nums[i]);
        for (int j = 1; j < n - 1; j++)
            ans = max(ans, (long long)(pre_max[j - 1] - nums[j]) * max_suffix[j + 1]);
        return ans >= 0 ? ans : 0;
    }
};
// @lc code=end
