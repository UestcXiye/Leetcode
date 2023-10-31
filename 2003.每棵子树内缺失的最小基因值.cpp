/*
 * @lc app=leetcode.cn id=2003 lang=cpp
 *
 * [2003] 每棵子树内缺失的最小基因值
 */

// @lc code=start
class Solution
{
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums)
    {
        int n = parents.size();
        vector<int> ans(n, 1);
        auto iter = find(nums.begin(), nums.end(), 1);
        if (iter == nums.end())
        {
            // 不存在基因值为 1 的点，所以每棵子树内缺失的最小基因值都为 1
            return ans;
        }
        // 建树
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++)
            g[parents[i]].push_back(i);

        unordered_set<int> visited;
        function<void(int)> dfs = [&](int x) -> void
        {
            visited.insert(nums[x]); // 标记基因值
            for (int son : g[x])
                if (!visited.count(nums[son]))
                    dfs(son);
        };
        int mex = 2; // 缺失的最小基因值
        int node = iter - nums.begin();
        while (node >= 0)
        {
            dfs(node);
            // node 子树包含这个基因值，mex 递增
            while (visited.count(mex))
                mex++;
            ans[node] = mex;      // 缺失的最小基因值
            node = parents[node]; // 往上走
        }
        return ans;
    }
};
// @lc code=end
