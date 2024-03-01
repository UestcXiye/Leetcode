/*
 * @lc app=leetcode.cn id=2581 lang=cpp
 *
 * [2581] 统计可能的树根数目
 */

// @lc code=start
class Solution
{
public:
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k)
    {
        int n = edges.size() + 1;
        // 边矩阵
        vector<vector<int>> g(n);
        for (auto &edge : edges)
        {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        // guesses 转成哈希集合
        unordered_set<long long> s;
        for (auto &e : guesses)
        { 
            // 两个 4 字节数压缩成一个 8 字节数
            s.insert((long long)e[0] << 32 | e[1]);
        }

        int cnt0 = 0;
        function<void(int, int)> dfs = [&](int x, int father)
        {
            for (int &y : g[x])
                if (y != father)
                {
                    // 以 0 为根时，猜对了
                    cnt0 += s.count((long long)x << 32 | y);
                    dfs(y, x);
                }
        };

        dfs(0, -1); // 0 没有父节点

        int ans = 0;
        function<void(int, int, int)> reRoot = [&](int x, int father, int cnt)
        {
            // 此时 cnt 就是以 x 为根时的猜对次数
            ans += cnt >= k;
            for (int &y : g[x])
                if (y != father)
                {
                    // 原来是对的，现在错了
                    // 如果有猜测 [x,y]，那么猜对次数减 1
                    int decrease = s.count((long long)x << 32 | y);
                    // 原来是错的，现在对了
                    // 如果有猜测 [y,x]，那么猜对次数加 1
                    int increase = s.count((long long)y << 32 | x);
                    int cur_cnt = cnt - decrease + increase;
                    reRoot(y, x, cur_cnt); // x 是 y 的父节点
                }
        };

        // 换根 DP
        reRoot(0, -1, cnt0); // 0 没有父节点

        return ans;
    }
};
// @lc code=end
