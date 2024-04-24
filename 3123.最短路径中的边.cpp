/*
 * @lc app=leetcode.cn id=3123 lang=cpp
 *
 * [3123] 最短路径中的边
 */

// @lc code=start
class Solution
{
public:
    vector<bool> findAnswer(int n, vector<vector<int>> &edges)
    {
        int m = edges.size();
        // 建图
        vector<vector<tuple<int, int, int>>> g(n);
        for (int i = 0; i < m; i++)
        {
            vector<int> edge = edges[i];
            int x = edge[0], y = edge[1], w = edge[2];
            g[x].emplace_back(y, w, i);
            g[y].emplace_back(x, w, i);
        }

        // Dijkstra
        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0LL;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty())
        {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x])
                continue;
            for (auto [y, w, _] : g[x])
            {
                int new_dis = dx + w;
                if (new_dis < dis[y])
                {
                    dis[y] = new_dis;
                    pq.emplace(new_dis, y);
                }
            }
        }

        vector<bool> ans(m, false);
        // 节点 0 到节点 n-1 不连通
        if (dis[n - 1] == LLONG_MAX)
            return ans;
        // 从终点出发 DFS
        vector<int> visited(n);
        function<void(int)> dfs = [&](int y)
        {
            visited[y] = true;
            for (auto &[x, w, i] : g[y])
            {
                if (dis[x] + w != dis[y])
                    continue;
                // dis[x] + w == dis[y]，说明边 x-y 在节点 0 到节点 n-1 的最短路上
                ans[i] = true;
                if (!visited[x])
                    dfs(x);
            }
        };
        dfs(n - 1);
        return ans;
    }
};
// @lc code=end
