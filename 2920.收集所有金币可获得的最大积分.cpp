/*
 * @lc app=leetcode.cn id=2920 lang=cpp
 *
 * [2920] 收集所有金币可获得的最大积分
 */

// @lc code=start
class Solution
{
public:
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int K)
    {
        int n = coins.size();
        const int MAXP = 20;

        // 建图
        vector<int> e[n];
        for (auto &edge : edges)
        {
            e[edge[0]].push_back(edge[1]);
            e[edge[1]].push_back(edge[0]);
        }

        const long long INF = 1e18;
        long long f[n][MAXP][2];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < MAXP; j++)
                f[i][j][0] = f[i][j][1] = -INF;
        // 树 dp
        function<void(int, int)> dp = [&](int sn, int fa)
        {
            long long now = coins[sn];
            for (int j = 0; j < MAXP; j++)
            {
                f[sn][j][0] = now - K;
                if (j > 0)
                    f[sn][j][1] = now;
                now >>= 1;
            }
            // 枚举子节点的操作
            for (int fn : e[sn])
                if (fn != fa)
                {
                    dp(fn, sn);
                    for (int j = 0; j < MAXP; j++)
                    {
                        // 这里的 min 是因为我们只考虑 log 次操作
                        long long best = max(f[fn][j][0], f[fn][min(MAXP - 1, j + 1)][1]);
                        f[sn][j][0] += best;
                        f[sn][j][1] += best;
                    }
                }
        };
        dp(0, -1);

        long long ans = 0;
        for (int j = 0; j < MAXP; j++)
            ans = max({ans, f[0][j][0], f[0][j][1]});
        return ans;
    }
};
// @lc code=end
