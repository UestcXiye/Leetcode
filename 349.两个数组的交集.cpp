/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        unordered_set<int> uset(nums1.begin(), nums1.end());
        for (int i = 0; i < n2; i++)
        {
            if (uset.count(nums2[i]))
            {
                ans.push_back(nums2[i]);
                uset.erase(nums2[i]);
            }
        }
        return ans;
    }
};
// @lc code=end
