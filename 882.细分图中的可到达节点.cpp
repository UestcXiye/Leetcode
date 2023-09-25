/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达节点
 */

// @lc code=start

// Dijkstra 算法

class Solution
{
public:
    int encode(int u, int v, int n)
    {
        return u * n + v;
    }

    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        vector<vector<pair<int, int>>> adList(n);
        for (vector<int> &edge : edges)
        {
            int u = edge[0], v = edge[1], nodes = edge[2];
            adList[u].push_back(make_pair(v, nodes));
            adList[v].push_back(make_pair(u, nodes));
        }
        unordered_map<int, int> used;
        unordered_set<int> visited;
        int reachableNodes = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        while (!pq.empty() && pq.top().first <= maxMoves)
        {
            auto [step, u] = pq.top();
            pq.pop();
            if (visited.count(u))
                continue;
            visited.insert(u);
            reachableNodes++;
            for (auto &[v, nodes] : adList[u])
            {
                if (nodes + step + 1 <= maxMoves && !visited.count(v))
                    pq.push(make_pair(nodes + step + 1, v));
                used[encode(u, v, n)] = min(nodes, maxMoves - step);
            }
        }
        for (vector<int> &edge : edges)
        {
            int u = edge[0], v = edge[1], nodes = edge[2];
            reachableNodes += min(nodes, used[encode(u, v, n)] + used[encode(v, u, n)]);
        }
        return reachableNodes;
    }
};
// @lc code=end
