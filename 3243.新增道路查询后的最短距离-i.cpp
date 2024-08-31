/*
 * @lc app=leetcode.cn id=3243 lang=cpp
 *
 * [3243] 新增道路查询后的最短距离 I
 */

// @lc code=start

// 广度优先搜索

// class Solution
// {
// public:
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
//     {
//         vector<int> e[n];
//         // 建图
//         for (int i = 1; i < n; i++)
//             e[i - 1].push_back(i);

//         auto bfs = [&]()
//         {
//             int dis[n];
//             memset(dis, -1, sizeof(dis));
//             queue<int> q;
//             q.push(0);
//             dis[0] = 0;
//             while (!q.empty())
//             {
//                 int sn = q.front();
//                 q.pop();
//                 for (int fn : e[sn])
//                     if (dis[fn] == -1)
//                     {
//                         q.push(fn);
//                         dis[fn] = dis[sn] + 1;
//                     }
//             }
//             return dis[n - 1];
//         };

//         vector<int> ans;
//         for (vector<int> &q : queries)
//         {
//             e[q[0]].push_back(q[1]);
//             int res = bfs();
//             ans.push_back(res);
//         }
//         return ans;
//     }
// };

// 动态规划

class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> dp(n);
        vector<vector<int>> from(n);
        // 初始化：dp[i] = i
        iota(dp.begin(), dp.end(), 0);

        vector<int> ans;
        // 状态转移
        for (vector<int> &q : queries)
        {
            int l = q[0], r = q[1];
            from[r].push_back(l);
            if (dp[l] + 1 < dp[r])
            {
                dp[r] = dp[l] + 1;
                // 更新后面的最短路
                for (int i = r + 1; i < n; i++)
                {
                    dp[i] = min(dp[i], dp[i - 1] + 1);
                    for (int j : from[i])
                    {
                        // 存在一条 j->i 的路径
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
            ans.push_back(dp[n-1]);
        }
        return ans;
    }
};
// @lc code=end
