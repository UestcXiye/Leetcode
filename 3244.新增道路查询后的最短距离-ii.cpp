/*
 * @lc app=leetcode.cn id=3244 lang=cpp
 *
 * [3244] 新增道路查询后的最短距离 II
 */

// @lc code=start

// 贪心

class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        set<int> s; // 存储所有城市的编号
        // 将每个城市加入到 set 中
        for (int i = 0; i < n; i++)
            s.insert(i);

        vector<int> ans;
        for (vector<int> &q : queries)
        {
            // [l, r) 之间的所有城市不可能在最短路里
            auto l = s.upper_bound(q[0]), r = s.lower_bound(q[1]);
            s.erase(l, r);
            // 剩余节点数减 1 即为当前的最短路径长度
            ans.push_back(s.size() - 1);
        }
        return ans;
    }
};

// 并查集

// class Solution
// {
// public:
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
//     {
//         vector<int> fa(n - 1);
//         iota(fa.begin(), fa.end(), 0);

//         // 非递归并查集
//         auto find = [&](int x) -> int
//         {
//             int rt = x;
//             while (fa[rt] != rt)
//             {
//                 rt = fa[rt];
//             }
//             while (fa[x] != rt)
//             {
//                 int tmp = fa[x];
//                 fa[x] = rt;
//                 x = tmp;
//             }
//             return rt;
//         };

//         vector<int> ans(queries.size());
//         int cnt = n - 1; // 并查集连通块个数
//         for (int qi = 0; qi < queries.size(); qi++)
//         {
//             int l = queries[qi][0], r = queries[qi][1] - 1;
//             int fr = find(r);
//             for (int i = find(l); i < r; i = find(i + 1))
//             {
//                 fa[i] = fr;
//                 cnt--;
//             }
//             ans[qi] = cnt;
//         }
//         return ans;
//     }
// };
// @lc code=end
