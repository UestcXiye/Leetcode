/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start

// 换根 DP（树型 DP 的变种）

class Solution
{
public:
    // 主函数
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        // 特判
        if (n == 1)
            return {0};

        // 边矩阵
        vector<vector<int>> g(n);
        for (auto &edge : edges)
        {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> height0(n, 0);
        // 计算以 0 号节点为根的树中，以各个节点为根的子树高
        function<void(int, int)> dfs = [&](int x, int father)
        {
            height0[x] = 1;
            int h = 0;
            // 遍历 x 的邻居 y
            for (int &y : g[x])
                if (y != father) // 避免访问父节点
                {
                    dfs(y, x); // x 是 y 的父节点
                    h = max(h, height0[y]);
                }
            height0[x] = h + 1;
        };

        dfs(0, -1); // 0 没有父节点

        vector<int> height(n, 0);
        function<void(int, int)> reRoot = [&](int x, int father)
        {
            // 计算子树高的最大值和次大值
            int first = 0;
            int second = 0;
            for (int &y : g[x])
            {
                if (height0[y] > first)
                {
                    second = first;
                    first = height0[y];
                }
                else if (height0[y] > second)
                    second = height0[y];
            }
            height[x] = first + 1;
            for (int &y : g[x])
                if (y != father) // 避免访问父节点
                {
                    // 更新以当前节点为根的子树高，换根到 v
                    height0[x] = (height0[y] != first ? first : second) + 1;
                    // 这句代码和前面的 height[x] = first + 1 保留一个即可
                    // height[y] = max(height0[y], height0[x] + 1);
                    reRoot(y, x); // x 是 y 的父节点
                }
        };

        // 换根 DP
        reRoot(0, -1); // 0 没有父节点

        vector<int> ans;
        int min_height = *min_element(height.begin(), height.end());
        for (int i = 0; i < n; i++)
        {
            if (height[i] == min_height)
                ans.push_back(i);
        }
        return ans;
    }
};

// 广度优先搜索

// 树的最长路径的最中间的节点即为最小高度树的根节点。
// 以下算法找到图中距离最远的两个节点与它们之间的路径：
// 1. 以任意节点 p 出现，利用广搜或者深搜找到以 p 为起点的最长路径的终点 x；
// 2. 以节点 x 出发，找到以 x 为起点的最长路径的终点 y；
// 3. x 到 y 之间的路径即为图中的最长路径，找到路径的中间节点即为根节点。

// class Solution
// {
// public:
//     // 主函数
//     vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
//     {
//         // 特判
//         if (n == 1)
//             return {0};

//         vector<vector<int>> adj(n); // 边矩阵
//         for (auto &edge : edges)
//         {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }
//         vector<int> parent(n, -1);
//         // 找到距离节点 0 最远的节点 x
//         int x = findLongestNode(0, parent, adj);
//         // 找到距离节点 x 最远的节点 y
//         int y = findLongestNode(x, parent, adj);
//         // 找到节点 x 到节点 y 的路径
//         vector<int> path;
//         parent[x] = -1;
//         while (y != -1)
//         {
//             path.push_back(y);
//             y = parent[y];
//         }
//         int m = path.size();
//         if (m % 2 == 0)
//             return {path[m / 2 - 1], path[m / 2]};
//         else
//             return {path[m / 2]};
//     }
//     // 辅函数
//     int findLongestNode(int u, vector<int> &parent, const vector<vector<int>> &adj)
//     {
//         int n = adj.size();
//         vector<int> dist(n, -1);
//         dist[u] = 0;
//         dfs(u, dist, parent, adj);
//         int maxDist = 0;
//         int node = -1;
//         for (int i = 0; i < n; i++)
//         {
//             if (dist[i] > maxDist)
//             {
//                 maxDist = dist[i];
//                 node = i;
//             }
//         }
//         return node;
//     }
//     void dfs(int u, vector<int> &dist, vector<int> &parent, const vector<vector<int>> &adj)
//     {
//         for (auto &v : adj[u])
//         {
//             if (dist[v] < 0)
//             {
//                 dist[v] = dist[u] + 1;
//                 parent[v] = u;
//                 dfs(v, dist, parent, adj);
//             }
//         }
//     }
// };
// @lc code=end
