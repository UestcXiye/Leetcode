/*
 * @lc app=leetcode.cn id=3108 lang=cpp
 *
 * [3108] 带权图里旅途的最小代价
 */

// @lc code=start
class Solution
{
    vector<vector<pair<int, int>>> g;
    vector<int> cc_and, ids;

    int dfs(int x)
    {
        ids[x] = cc_and.size(); // 记录每个点所在连通块的编号
        int and_ = -1;          // 全为 1，性质：-1 & x = x
        for (auto &[y, w] : g[x])
        {
            and_ &= w;
            if (ids[y] < 0) // 没有访问过
                and_ &= dfs(y);
        }
        return and_;
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        g.resize(n);
        for (auto &edge : edges)
        {
            int x = edge[0], y = edge[1], w = edge[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }

        ids.resize(n, -1); // 记录每个点所在连通块的编号
        for (int i = 0; i < n; i++)
        {
            if (ids[i] < 0) // 没有访问过
            {
                // 记录每个连通块的边权的 AND
                cc_and.push_back(dfs(i));
            }
        }

        vector<int> ans;
        ans.reserve(query.size()); // 预分配空间
        for (auto &q : query)
        {
            int s = q[0], t = q[1];
            if (s == t)
                ans.push_back(0);
            else
                ans.push_back(ids[s] != ids[t] ? -1 : cc_and[ids[s]]);
        }
        return ans;
    }
};
// @lc code=end
