/*
 * @lc app=leetcode.cn id=3132 lang=cpp
 *
 * [3132] 找出与数组相加的整数 II
 */

// @lc code=start
class Solution
{
public:
    int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        ranges::sort(nums1);
        ranges::sort(nums2);
        for (int i = 2; i > 0; i--)
        {
            int diff = nums2[0] - nums1[i];
            // 在 {nums1[i] + diff} 中找子序列 nums2
            int j = 0;
            for (int k = i; k < nums1.size(); k++)
            {
                if (j < nums2.size() && nums2[j] == nums1[k] + diff)
                    j++;
            }
            if (j == nums2.size())
                return diff;
        }
        return nums2[0] - nums1[0];
    }
};
// @lc code=end
