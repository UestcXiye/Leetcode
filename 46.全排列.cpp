/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    // 主函数
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);
        return ans;
    }
    // 辅函数
    void backtrack(vector<int> &nums, int level, vector<vector<int>> &ans)
    {
        if (level == nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); i++)
        {
            swap(nums[i], nums[level]);      // 修改当前节点状态
            backtrack(nums, level + 1, ans); // 递归子节点
            swap(nums[i], nums[level]);      // 回改当前节点状态
        }
    }
};
// @lc code=end
