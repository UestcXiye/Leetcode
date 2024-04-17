/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start

// 朴素 Dijkstra（适用于稠密图）

// class Solution
// {
// private:
//     const int inf = INT_MAX / 2;

// public:
//     int networkDelayTime(vector<vector<int>> &times, int n, int k)
//     {
//         vector<vector<int>> g(n, vector<int>(n, inf));
//         for (auto &time : times)
//         {
//             int u = time[0] - 1, v = time[1] - 1;
//             int w = time[2];
//             g[u][v] = w;
//         }
//         // dist[i] 表示点 k 到其他节点的最短距离
//         vector<int> dist(n, inf);
//         dist[k - 1] = 0;
//         vector<int> used(n);
//         for (int i = 0; i < n; i++)
//         {
//             int x = -1;
//             for (int y = 0; y < n; y++)
//                 if (!used[y] && (x == -1 || dist[y] < dist[x]))
//                     x = y;
//             used[x] = true;
//             for (int y = 0; y < n; y++)
//                 dist[y] = min(dist[y], dist[x] + g[x][y]);
//         }

//         int ans = *max_element(dist.begin(), dist.end());
//         return ans == inf ? -1 : ans;
//     }
// };

// 堆优化 Dijkstra（适用于稀疏图）

class Solution
{
private:
    const int inf = INT_MAX / 2;

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> g(n); // 邻接表
        for (auto &time : times)
        {
            int u = time[0] - 1, v = time[1] - 1;
            int w = time[2];
            g[u].emplace_back(v, w);
        }
        // dist[i] 表示点 k 到其他节点的最短距离
        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k - 1);
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
                if (new_dist < dist[y])
                {
                    dist[y] = new_dist; // 更新 x 的邻居的最短路
                    pq.emplace(new_dist, y);
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};
// @lc code=end
