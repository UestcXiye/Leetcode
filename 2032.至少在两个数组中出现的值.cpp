/*
 * @lc app=leetcode.cn id=2032 lang=cpp
 *
 * [2032] 至少在两个数组中出现的值
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        set<int> s3(nums3.begin(), nums3.end());
        vector<int> ans;
        for (int i = 1; i <= 100; i++)
            if (s1.count(i) + s2.count(i) + s3.count(i) > 1)
                ans.push_back(i);
        return ans;
    }
};
// @lc code=end
