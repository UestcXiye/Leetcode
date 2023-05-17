/*
 * @lc app=leetcode.cn id=2089 lang=cpp
 *
 * [2089] 找出数组排序后的目标下标
 */

// @lc code=start
class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
            if (nums[i] == target)
                ans.push_back(i);
        return ans;
    }
};
// @lc code=end
