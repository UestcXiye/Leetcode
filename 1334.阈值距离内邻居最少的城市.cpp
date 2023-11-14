/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */

// @lc code=start

// Floyd 算法

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // 初始化邻接矩阵
        vector<vector<int>> grid(n, vector<int>(n, INT_MAX / 2));
        // 建图
        for (vector<int> &edge : edges)
        {
            int from = edge[0], to = edge[1], weight = edge[2];
            grid[from][to] = grid[to][from] = weight;
        }
        // 求最短路
        for (int k = 0; k < n; k++)
        {
            grid[k][k] = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
        }
        // 求答案
        pair<int, int> ans(INT_MAX / 2, -1);
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
                if (grid[i][j] <= distanceThreshold)
                    count++;
            if (count <= ans.first)
                ans = make_pair(count, i);
        }
        return ans.second;
    }
};

// Dijkstra 算法

// class Solution
// {
// public:
//     int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
//     {
//         vector<vector<int>> dis(n, vector<int>(n, INT_MAX / 2));
//         vector<vector<int>> vis(n, vector<int>(n, false));
//         vector<vector<int>> mp(n, vector<int>(n, INT_MAX / 2));
//         // 建图
//         for (auto &eg : edges)
//         {
//             int from = eg[0], to = eg[1], weight = eg[2];
//             mp[from][to] = mp[to][from] = weight;
//         }
//         // 求最短路
//         for (int i = 0; i < n; ++i)
//         {
//             dis[i][i] = 0;
//             for (int j = 0; j < n; ++j)
//             {
//                 int t = -1;
//                 for (int k = 0; k < n; ++k)
//                 {
//                     if (!vis[i][k] && (t == -1 || dis[i][k] < dis[i][t]))
//                     {
//                         t = k;
//                     }
//                 }
//                 for (int k = 0; k < n; ++k)
//                 {
//                     dis[i][k] = min(dis[i][k], dis[i][t] + mp[t][k]);
//                 }
//                 vis[i][t] = true;
//             }
//         }
//         // 求答案
//         pair<int, int> ans(INT_MAX / 2, -1);
//         for (int i = 0; i < n; i++)
//         {
//             int count = 0;
//             for (int j = 0; j < n; j++)
//                 if (dis[i][j] <= distanceThreshold)
//                     count++;
//             if (count <= ans.first)
//                 ans = make_pair(count, i);
//         }
//         return ans.second;
//     }
// };
// @lc code=end
