/*
 * @lc app=leetcode.cn id=3112 lang=cpp
 *
 * [3112] 访问消失节点的最少时间
 */

// @lc code=start

// 堆优化 Dijkstra（适用于稀疏图）

class Solution
{
private:
    const int inf = INT_MAX / 2;

public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        vector<vector<pair<int, int>>> g(n); // 邻接表
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        // dist[i] 表示点 k 到其他节点的最短距离
        vector<int> dist(n, inf);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty())
        {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dist[x])
            { // x 之前出堆过
                continue;
            }
            for (auto &[y, d] : g[x])
            {
                int new_dist = dx + d;
                if (new_dist < disappear[y] && new_dist < dist[y])
                {
                    dist[y] = new_dist; // 更新 x 的邻居的最短路
                    pq.emplace(new_dist, y);
                }
            }
        }

        for (int &d : dist)
            if (d == inf)
                d = -1;
        return dist;
    }
};
// @lc code=end
