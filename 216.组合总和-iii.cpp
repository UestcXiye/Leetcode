/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // 特判
        if (n < k)
            return {};

        vector<vector<int>> ans;
        vector<int> path;
        // upper 是当前可选的最大数，curSum 是当前组合元素总和
        function<void(int, int)> backtrack = [&](int upper, int curSum)
        {
            // 还剩 remain 个数字要选
            int remain = k - path.size();
            // 剪枝
            if (curSum > n || curSum + (2 * upper - remain + 1) * remain / 2 < n)
                return;
            if (remain == 0 && curSum == n)
            {
                ans.push_back(path);
                return;
            }
            // 从大的数开始选
            for (int i = upper; i >= 1; i--)
            {
                path.push_back(i);
                backtrack(i - 1, curSum + i);
                path.pop_back(); // 回溯
            }
        };
        // 入口
        backtrack(min(9, n), 0);
        return ans;
    }
};
// @lc code=end
