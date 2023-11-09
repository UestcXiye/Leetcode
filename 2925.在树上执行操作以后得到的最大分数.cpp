/*
 * @lc app=leetcode.cn id=2925 lang=cpp
 *
 * [2925] 在树上执行操作以后得到的最大分数
 */

// @lc code=start
class Solution
{
public:
    long long maximumScoreAfterOperations(vector<vector<int>> &edges, vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> g(n);
        g[0].push_back(-1); // 避免误把根节点当作叶子
        for (vector<int> &edge : edges)
        {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        // dfs(x, fa) 计算以 x 为根的子树是健康时，失去的最小分数
        function<long long(int, int)> dfs = [&](int x, int father) -> long long
        {
            if (g[x].size() == 1) // x 是叶子
                return values[x];
            long long loss = 0;
            for (int &y : g[x])
            {
                if (y != father)
                {
                    // 计算以 y 为根的子树是健康时，失去的最小分数
                    loss += dfs(y, x);
                }
            }
            return min((long long)values[x], loss); // 两种情况取最小值
        };
        return accumulate(values.begin(), values.end(), 0LL) - dfs(0, -1);
    }
};
// @lc code=end
