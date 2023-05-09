/*
 * @lc app=leetcode.cn id=2540 lang=cpp
 *
 * [2540] 最小公共值
 */

// @lc code=start
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        while (i < len1 && j < len2)
        {
            if (nums1[i] == nums2[j])
                return nums1[i];
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return -1;
    }
};
// @lc code=end
