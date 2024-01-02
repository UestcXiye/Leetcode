/*
 * @lc app=leetcode.cn id=2966 lang=cpp
 *
 * [2966] 划分数组并满足最大差限制
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        if (nums.empty())
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 3)
        {
            if (nums[i + 2] - nums[i] > k)
                return {};
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};
// @lc code=end
