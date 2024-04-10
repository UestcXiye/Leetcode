/*
 * @lc app=leetcode.cn id=3105 lang=cpp
 *
 * [3105] 最长的严格递增或递减子数组
 */

// @lc code=start
class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                dp1[i] = max(dp1[i - 1] + 1, dp1[i]);
            if (nums[i] < nums[i - 1])
                dp2[i] = max(dp2[i - 1] + 1, dp2[i]);
        }
        return max(*max_element(dp1.begin(), dp1.end()), *max_element(dp2.begin(), dp2.end()));
    }
};
// @lc code=end
