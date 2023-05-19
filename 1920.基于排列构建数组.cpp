/*
 * @lc app=leetcode.cn id=1920 lang=cpp
 *
 * [1920] 基于排列构建数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = nums[nums[i]];
        return ans;
    }
};
// @lc code=end
