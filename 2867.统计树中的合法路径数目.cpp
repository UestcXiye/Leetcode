/*
 * @lc app=leetcode.cn id=2867 lang=cpp
 *
 * [2867] 统计树中的合法路径数目
 */

// @lc code=start

// 树型 DP

class Solution
{
private:
    #define MAXN (int)1e5
    bool inited = false;
    bool flag[MAXN + 10];

    // 筛法预处理 1e5 以内的质数
    void init()
    {
        if (inited)
            return;
        inited = true;

        memset(flag, 0, sizeof(flag));
        flag[0] = flag[1] = true;
        for (int i = 2; i * i <= MAXN; i++)
            if (!flag[i])
                for (int j = i << 1; j <= MAXN; j += i)
                    flag[j] = true;
    }

public:
    long long countPaths(int n, vector<vector<int>> &edges)
    {
        init();

        vector<int> e[n + 1];
        for (auto &edge : edges)
        {
            e[edge[0]].push_back(edge[1]);
            e[edge[1]].push_back(edge[0]);
        }

        long long ans = 0;
        int f[n + 1], g[n + 1];
        // 树 dp
        function<void(int, int)> dfs = [&](int sn, int fa)
        {
            if (flag[sn])
                f[sn] = 1, g[sn] = 0;
            else
                f[sn] = 0, g[sn] = 1;
            for (int fn : e[sn])
                if (fn != fa)
                {
                    dfs(fn, sn);
                    // 路径上深度最低的节点为 sn，这样的合法路径有几条
                    ans += f[sn] * g[fn] + g[sn] * f[fn];
                    // 更新以 sn 为起点，且走到子树里的路径数量
                    if (flag[sn])
                    {
                        f[sn] += f[fn];
                        g[sn] += g[fn];
                    }
                    else
                    {
                        g[sn] += f[fn];
                    }
                }
        };
        dfs(1, 0);
        return ans;
    }
};
// @lc code=end
