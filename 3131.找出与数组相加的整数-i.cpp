/*
 * @lc app=leetcode.cn id=3131 lang=cpp
 *
 * [3131] 找出与数组相加的整数 I
 */

// @lc code=start
class Solution
{
public:
    int addedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        ranges::sort(nums1);
        ranges::sort(nums2);
        return nums2[0] - nums1[0];
    }
};
// @lc code=end
