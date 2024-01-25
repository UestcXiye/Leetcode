/*
 * @lc app=leetcode.cn id=2858 lang=cpp
 *
 * [2858] 可以到达每一个节点的最少边反转次数
 */

// @lc code=start
class Solution
{
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>> &edges)
    {
        // g[x] 表示 x 的所有邻居
        vector<vector<pair<int, int>>> g(n);
        for (auto &edge : edges)
        {
            int x = edge[0], y = edge[1];
            // x->y 视为正向，标记为 1；反向标记为 -1
            g[x].push_back(pair<int, int>(y, 1));
            g[y].push_back(pair<int, int>(x, -1));
        }
        // size[i] 为 子树 i 的大小
        // vector<int> size(n, 1); // 注意这里初始化成 1 了，下面只需要累加儿子的子树大小
        vector<int> answer(n);

        function<void(int, int)> dfs = [&](int x, int father)
        {
            // 遍历 x 的邻居 y
            for (auto &[y, dir] : g[x])
                if (y != father) // 避免访问父节点
                {
                    answer[0] += dir < 0;
                    dfs(y, x); // x 是 y 的父节点
                }
        };

        dfs(0, -1); // 0 没有父节点

        function<void(int, int)> reRoot = [&](int x, int father)
        {
            // 遍历 x 的邻居 y
            for (auto &[y, dir] : g[x])
                if (y != father) // 避免访问父节点
                {
                    answer[y] = answer[x] + dir;
                    reRoot(y, x); // x 是 y 的父节点
                }
        };

        reRoot(0, -1); // 0 没有父节点

        return answer;
    }
};
// @lc code=end
