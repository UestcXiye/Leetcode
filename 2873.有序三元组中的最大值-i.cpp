/*
 * @lc app=leetcode.cn id=2873 lang=cpp
 *
 * [2873] 有序三元组中的最大值 I
 */

// @lc code=start
class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = INT_MIN;
        for (int i = 0; i < n - 2; i++)
            for (int j = i + 1; j < n - 1; j++)
                for (int k = j + 1; k < n; k++)
                    ans = max(ans, (long long)(nums[i] - nums[j]) * nums[k]);
        return ans >= 0 ? ans : 0;
    }
};
// @lc code=end
