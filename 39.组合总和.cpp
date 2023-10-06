/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> comb;
        backtracking(candidates, ans, 0, target, comb);
        return ans;
    }
    // 辅函数 - 回溯
    void backtracking(vector<int> &candidates, vector<vector<int>> &ans, int level, int remain, vector<int> &comb)
    {
        if (level == candidates.size())
            return;
        if (remain == 0)
        {
            ans.push_back(comb);
            return;
        }
        backtracking(candidates, ans, level + 1, remain, comb);
        if (remain >= candidates[level])
        {
            comb.push_back(candidates[level]);
            backtracking(candidates, ans, level, remain - candidates[level], comb);
            comb.pop_back();
        }
    }
};
// @lc code=end
