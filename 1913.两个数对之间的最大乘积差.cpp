/*
 * @lc app=leetcode.cn id=1913 lang=cpp
 *
 * [1913] 两个数对之间的最大乘积差
 */

// @lc code=start
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};
// @lc code=end
