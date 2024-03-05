/*
 * @lc app=leetcode.cn id=3065 lang=cpp
 *
 * [3065] 超过阈值的最少操作数 I
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return lower_bound(nums.begin(), nums.end(), k) - nums.begin();
    }
};
// @lc code=end
