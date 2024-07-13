/*
 * @lc app=leetcode.cn id=3203 lang=cpp
 *
 * [3203] 合并两棵树后的最小直径
 */

// @lc code=start
class Solution
{
private:
    // 求树的直径
    int diameter(vector<vector<int>> &edges)
    {
        vector<vector<int>> g(edges.size() + 1);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int res = 0;
        auto dfs = [&](auto &&dfs, int x, int fa) -> int
        {
            int max_len = 0;
            for (auto y : g[x])
            {
                if (y != fa)
                {
                    int sub_len = dfs(dfs, y, x) + 1;
                    res = max(res, max_len + sub_len);
                    max_len = max(max_len, sub_len);
                }
            }
            return max_len;
        };
        dfs(dfs, 0, -1);
        return res;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        // 设树 1 的长度为 d1
        int d1 = diameter(edges1);
        // 设树 2 的长度为 d2
        int d2 = diameter(edges2);
        // 答案为三种情况的最大值：
        // 1. d1
        // 2. d2
        // 3. 连接两棵树的直径中点，(d1 + 1) / 2 + (d2 + 1) / 2 + 1
        return max(max(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
    }
};
// @lc code=end
