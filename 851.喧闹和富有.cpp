/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

// @lc code=start
class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size();
        vector<vector<int>> g(n);
        for (vector<int> &r : richer)
            g[r[1]].push_back(r[0]);

        vector<int> ans(n, -1);
        function<void(int)> dfs = [&](int x)
        {
            if (ans[x] != -1)
                return;
            ans[x] = x;
            for (int &y : g[x])
            {
                dfs(y);
                if (quiet[ans[y]] < quiet[ans[x]])
                    ans[x] = ans[y];
            }
        };
        for (int i = 0; i < n; i++)
            dfs(i);

        return ans;
    }
};
// @lc code=end
