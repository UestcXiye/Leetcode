/*
 * @lc app=leetcode.cn id=3310 lang=cpp
 *
 * [3310] 移除可疑的方法
 */

// @lc code=start
class Solution
{
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>> &invocations)
    {
        vector<vector<int>> grid(n);
        // 建图
        for (vector<int> &invocation : invocations)
        {
            int from = invocation[0], to = invocation[1];
            grid[from].push_back(to);
        }

        vector<bool> suspicious(n, false); // 可疑方法

        function<void(int)> dfs = [&](int x)
        {
            suspicious[x] = true;
            for (int &y : grid[x])
                if (suspicious[y] == false)
                    dfs(y);
        };

        dfs(k);

        for (vector<int> &invocation : invocations)
        {
            int from = invocation[0], to = invocation[1];
            if (suspicious[from] == false && suspicious[to] == true)
            {
                // 有【非可疑方法】->【可疑方法】的边，无法移除可疑方法
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        // 移除所有可疑方法
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (suspicious[i] == false)
                ans.push_back(i);
        return ans;
    }
};
// @lc code=end
