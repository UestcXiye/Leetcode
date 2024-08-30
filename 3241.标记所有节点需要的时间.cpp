/*
 * @lc app=leetcode.cn id=3241 lang=cpp
 *
 * [3241] 标记所有节点需要的时间
 */

// @lc code=start
class Solution
{
public:
    vector<int> timeTaken(vector<vector<int>> &edges)
    {
        vector<vector<int>> g(edges.size() + 1);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        // nodes[x] 保存子树 x 的最大深度 max_d，次大深度 max_d2，以及最大深度要往儿子 my 走
        vector<tuple<int, int, int>> nodes(g.size());
        auto dfs = [&](auto &&dfs, int x, int fa) -> int
        {
            int max_d = 0, max_d2 = 0, my = 0;
            for (int y : g[x])
            {
                if (y == fa)
                {
                    continue;
                }
                int depth = dfs(dfs, y, x) + 2 - y % 2; // 从 x 出发，往 my 方向的最大深度
                if (depth > max_d)
                {
                    max_d2 = max_d;
                    max_d = depth;
                    my = y;
                }
                else if (depth > max_d2)
                {
                    max_d2 = depth;
                }
            }
            nodes[x] = {max_d, max_d2, my};
            return max_d;
        };
        dfs(dfs, 0, -1);

        vector<int> ans(g.size());
        auto reroot = [&](auto &&reroot, int x, int fa, int from_up) -> void
        {
            auto &[max_d, max_d2, my] = nodes[x];
            ans[x] = max(from_up, max_d);
            for (int y : g[x])
            {
                if (y != fa)
                {
                    reroot(reroot, y, x, max(from_up, (y == my ? max_d2 : max_d)) + 2 - x % 2);
                }
            }
        };
        reroot(reroot, 0, -1, 0);
        return ans;
    }
};
// @lc code=end
