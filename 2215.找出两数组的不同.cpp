/*
 * @lc app=leetcode.cn id=2215 lang=cpp
 *
 * [2215] 找出两数组的不同
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> answer(2);
        unordered_set<int> uset1(nums1.begin(), nums1.end());
        unordered_set<int> uset2(nums2.begin(), nums2.end());
        for (int num : uset1)
            if (!uset2.count(num))
                answer[0].push_back(num);
        for (int num : uset2)
            if (!uset1.count(num))
                answer[1].push_back(num);
        return answer;
    }
};
// @lc code=end
