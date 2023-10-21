/*
 * @lc app=leetcode.cn id=2836 lang=cpp
 *
 * [2836] 在传球游戏中最大化函数值
 */

// @lc code=start
class Solution
{
public:
    long long getMaxFunctionValue(vector<int> &receiver, long long k)
    {
        int n = receiver.size();
        int m = 64 - __builtin_clzll(k); // k 的二进制长度
        vector<vector<pair<int, long long>>> pa(m, vector<pair<int, long long>>(n));
        for (int i = 0; i < n; i++)
            pa[0][i] = {receiver[i], receiver[i]};
        for (int i = 0; i < m - 1; i++)
        {
            for (int x = 0; x < n; x++)
            {
                auto [p, s] = pa[i][x];
                auto [pp, ss] = pa[i][p];
                pa[i + 1][x] = {pp, s + ss}; // 合并节点值之和
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long sum = i;
            int x = i;
            for (long long j = k; j; j &= j - 1)
            {
                auto [p, s] = pa[__builtin_ctzll(j)][x];
                sum += s;
                x = p;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end
