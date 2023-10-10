/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> comb;
        sort(nums.begin(), nums.end());
        backtracking(ans, nums, 0, comb);
        return ans;
    }
    // 辅函数 - 回溯
    void backtracking(vector<vector<int>> &ans, vector<int> &nums, int start, vector<int> &comb)
    {
        ans.push_back(comb);
        if (start >= nums.size())
            return;
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            comb.push_back(nums[i]);
            backtracking(ans, nums, i + 1, comb);
            comb.pop_back();
        }
    }
};
// @lc code=end
