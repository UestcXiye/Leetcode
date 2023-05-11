/*
 * @lc app=leetcode.cn id=2395 lang=cpp
 *
 * [2395] 和相等的子数组
 */

// @lc code=start
class Solution
{
public:
    bool findSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sum(n - 1);
        for (int i = 0; i < n - 1; i++)
            sum[i] = nums[i] + nums[i + 1];
        for (int i = 0; i < sum.size() - 1; i++)
            for (int j = i + 1; j < sum.size(); j++)
                if (sum[i] == sum[j])
                    return true;
        return false;
    }
};
// @lc code=end
