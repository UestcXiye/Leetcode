/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
private:
    vector<bool> visited;

public:
    // 主函数
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> seq;
        visited = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, ans, seq);
        return ans;
    }
    // 辅函数
    void backtrack(vector<int> &nums, int level, vector<vector<int>> &ans, vector<int> &seq)
    {
        if (level == nums.size())
        {
            ans.emplace_back(seq);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
            {
                continue;
            }
            seq.emplace_back(nums[i]);
            visited[i] = true;
            backtrack(nums, level + 1, ans, seq);
            visited[i] = false;
            seq.pop_back();
        }
    }
};
// @lc code=end
