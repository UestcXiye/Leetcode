/*
 * @lc app=leetcode.cn id=3067 lang=cpp
 *
 * [3067] 在带权树网络中统计可连接服务器对数目
 */

// @lc code=start
class Solution
{
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {
        // 对于树，节点数 = 边数 + 1
        int n = edges.size() + 1;
        // 建图
        vector<vector<pair<int, int>>> g(n);
        for (auto &edge : edges)
        {
            int x = edge[0], y = edge[1], weight = edge[2];
            g[x].push_back({y, weight});
            g[y].push_back({x, weight});
        }

        function<int(int, int, int)> dfs = [&](int x, int father, int pathSum) -> int
        {
            int cnt = pathSum % signalSpeed == 0;
            for (auto &[y, weight] : g[x])
            {
                if (y != father)
                    cnt += dfs(y, x, pathSum + weight);
            }
            return cnt;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int sum = 0; // 前面遍历的子树中符合要求的节点总数
            // 遍历子节点
            for (auto &[y, weight] : g[i])
            {
                int cnt = dfs(y, i, weight);
                // 乘法原理
                ans[i] += cnt * sum;
                sum += cnt;
            }
        }
        return ans;
    }
};
// @lc code=end
