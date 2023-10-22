/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start
class UnionFind
{
    vector<int> father, size;

public:
    UnionFind(int n) : father(n), size(n, 1)
    {
        // iota函数可以把数组初始化为 0 到 n-1
        iota(father.begin(), father.end(), 0);
    }
    int find(int x)
    {
        if (x == father[x])
            return x;
        else
            return find(father[x]);
    }
    void connect(int p, int q)
    {
        int fa_p = find(p), fa_q = find(q);
        if (fa_p != fa_q)
            father[fa_p] = fa_q;
    }
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
};

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        UnionFind uf(n);
        for (vector<int> &edge : edges)
            uf.connect(edge[0], edge[1]);
        return uf.isConnected(source, destination);
    }
};

// class Solution
// {
// public:
//     bool dfs(int source, int destination, vector<vector<int>> &adj, vector<bool> &visited)
//     {
//         if (source == destination)
//         {
//             return true;
//         }
//         visited[source] = true;
//         for (int next : adj[source])
//         {
//             if (!visited[next] && dfs(next, destination, adj, visited))
//             {
//                 return true;
//             }
//         }
//         return false;
//     }

//     bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
//     {
//         vector<vector<int>> adj(n);
//         for (auto &edge : edges)
//         {
//             int x = edge[0], y = edge[1];
//             adj[x].emplace_back(y);
//             adj[y].emplace_back(x);
//         }
//         vector<bool> visited(n, false);
//         return dfs(source, destination, adj, visited);
//     }
// };

// @lc code=end
