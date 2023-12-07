/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
 */

// @lc code=start

// 深度优先搜索

// class Solution
// {
// public:
//     int minReorder(int n, vector<vector<int>> &connections)
//     {
//         vector<vector<pair<int, int>>> edges(n);
//         for (vector<int> connection : connections)
//         {
//             int from = connection[0], to = connection[1];
//             // 1 表示原树中有一条 a->b 的边
//             edges[from].push_back(pair<int, int>(to, 1));
//             // 0 表示反向边
//             edges[to].push_back(pair<int, int>(from, 0));
//         }
//         function<int(int, int)> dfs = [&](int x, int father) -> int
//         {
//             int res = 0;
//             for (pair<int, int> edge : edges[x])
//                 if (edge.first != father)
//                 {
//                     // 原树中有一条 x->edge.first 的边，需要反向
//                     if (edge.second == 1)
//                         res++;
//                     // 递归求解
//                     res += dfs(edge.first, x);
//                 }
//             return res;
//         };
//         return dfs(0, -1);
//     }
// };

// 广度优先搜索

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, int>>> edges(n);
        for (vector<int> connection : connections)
        {
            int from = connection[0], to = connection[1];
            // 1 表示原树中有一条 a->b 的边
            edges[from].push_back(pair<int, int>(to, 1));
            // 0 表示反向边
            edges[to].push_back(pair<int, int>(from, 0));
        }

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int res = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (pair<int, int> edge : edges[x])
            {
                int y = edge.first;
                if (visited[y] == false)
                {
                    visited[y] = true;
                    q.push(y);
                    if (edge.second == 1)
                        res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
