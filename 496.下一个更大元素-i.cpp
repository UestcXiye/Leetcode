/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < n1; i++)
        {
            int number = nums1[i];
            int j = 0;
            while (j < n2 && nums2[j] != number)
                j++;
            j++;
            while (j < n2 && nums2[j] <= number)
                j++;
            if (j == n2)
                ans.push_back(-1);
            else
                ans.push_back(nums2[j]);
        }
        return ans;
    }
};
// @lc code=end
