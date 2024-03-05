/*
 * @lc app=leetcode.cn id=3068 lang=cpp
 *
 * [3068] 最大节点价值之和
 */

// @lc code=start
class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        function<pair<long long, long long>(int, int)> dfs = [&](int x, int father) -> pair<long long, long long>
        {
            long long f0 = 0, f1 = LLONG_MIN; // f[x][0] 和 f[x][1]
            for (auto &y : g[x])
            {
                if (y != father)
                {
                    auto [r0, r1] = dfs(y, x);
                    long long t = max(f1 + r0, f0 + r1);
                    f0 = max(f0 + r0, f1 + r1);
                    f1 = t;
                }
            }
            return {max(f0 + nums[x], f1 + (nums[x] ^ k)), max(f1 + nums[x], f0 + (nums[x] ^ k))};
        };
        
        return dfs(0, -1).first;
    }
};

// @lc code=end
