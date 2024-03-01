/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 */

// @lc code=start

// 换根 DP（树型 DP 的变种）

class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        // g[x] 表示 x 的所有邻居
        vector<vector<int>> g(n);
        for (auto &edge : edges)
        {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        // size[i] 为 子树 i 的大小
        // 注意这里初始化成 1 了，下面只需要累加儿子的子树大小
        vector<int> size(n, 1);

        vector<int> answer(n);

        function<void(int, int, int)> dfs = [&](int x, int father, int depth)
        {
            answer[0] += depth; // depth 为 0 到 x 的距离
            // 遍历 x 的邻居 y
            for (int &y : g[x])
                if (y != father) // 避免访问父节点
                {
                    dfs(y, x, depth + 1); // x 是 y 的父节点
                    size[x] += size[y];   // 累加 x 的儿子 y 的子树大小
                }
        };

        // 求 0 到所有其他节点之间的距离之和
        // 求每个子树的大小
        dfs(0, -1, 0); // 0 没有父节点

        function<void(int, int)> reRoot = [&](int x, int father)
        {
            // 遍历 x 的邻居 y
            for (int y : g[x])
            {
                if (y != father) // 避免访问父节点
                {
                    answer[y] = answer[x] + n - 2 * size[y];
                    reRoot(y, x); // x 是 y 的父节点
                }
            }
        };

        // 换根 DP
        reRoot(0, -1); // 0 没有父节点

        return answer;
    }
};
// @lc code=end
