/*
 * @lc app=leetcode.cn id=2977 lang=cpp
 *
 * [2977] 转换字符串的最小成本 II
 */

// @lc code=start
struct Node
{
    Node *son[26]{};
    int sid = -1; // 字符串的编号
};

class Solution
{
public:
    long long
    minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost)
    {
        Node *root = new Node();
        int sid = 0;
        auto put = [&](string &s) -> int
        {
            Node *o = root;
            for (char b : s)
            {
                int i = b - 'a';
                if (o->son[i] == nullptr)
                    o->son[i] = new Node();
                o = o->son[i];
            }
            if (o->sid < 0)
                o->sid = sid++;
            return o->sid;
        };

        // 初始化距离矩阵
        int m = cost.size();
        vector<vector<int>> dis(m * 2, vector<int>(m * 2, INT_MAX / 2));
        for (int i = 0; i < m * 2; i++)
            dis[i][i] = 0;
        for (int i = 0; i < m; i++)
        {
            int x = put(original[i]);
            int y = put(changed[i]);
            dis[x][y] = min(dis[x][y], cost[i]);
        }

        // Floyd 求任意两点最短路
        for (int k = 0; k < sid; k++)
        {
            for (int i = 0; i < sid; i++)
            {
                if (dis[i][k] == INT_MAX / 2) // 加上这句话，巨大优化！
                    continue;
                for (int j = 0; j < sid; j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int n = source.size();
        vector<long long> dp(n + 1);
        for (int i = n - 1; i >= 0; i--)
        {
            // 不修改 source[i]
            dp[i] = source[i] == target[i] ? dp[i + 1] : LONG_LONG_MAX / 2;
            Node *p = root, *q = root;
            for (int j = i; j < n; j++)
            {
                p = p->son[source[j] - 'a'];
                q = q->son[target[j] - 'a'];
                if (p == nullptr || q == nullptr)
                    break;
                if (p->sid < 0 || q->sid < 0)
                    continue;
                // 修改从 i 到 j 的这一段
                int d = dis[p->sid][q->sid];
                if (d < INT_MAX / 2)
                    dp[i] = min(dp[i], dis[p->sid][q->sid] + dp[j + 1]);
            }
        }
        return dp[0] < LONG_LONG_MAX / 2 ? dp[0] : -1;
    }
};
// @lc code=end
