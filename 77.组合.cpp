/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    // 主函数
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> combo(k, 0);
        int count = 0;
        backtrack(ans, combo, count, 1, n, k);
        return ans;
    }
    // 辅函数
    void backtrack(vector<vector<int>> &ans, vector<int> &combo, int &count, int pos, int n, int k)
    {
        if (count == k)
        {
            ans.push_back(combo);
            return;
        }
        for (int i = pos; i <= n; i++)
        {
            combo[count] = i; // 修改当前节点状态
            count++;
            backtrack(ans, combo, count, i + 1, n, k); // 递归子节点
            count--;                                   // 回改当前节点状态
        }
    }
};
// @lc code=end
