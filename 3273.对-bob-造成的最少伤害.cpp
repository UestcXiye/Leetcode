/*
 * @lc app=leetcode.cn id=3273 lang=cpp
 *
 * [3273] 对 Bob 造成的最少伤害
 */

// @lc code=start
class Solution
{
public:
    long long minDamage(int power, vector<int> &damage, vector<int> &health)
    {
        int n = damage.size();
        vector<pair<int, int>> comb(n);
        for (int i = 0; i < n; i++)
        {
            int k = ceil(1.0 * health[i] / power);
            comb[i] = make_pair(k, damage[i]);
        }
        sort(comb.begin(), comb.end(),
             [&](const pair<int, int> &p1, const pair<int, int> &p2)
             { return p1.first * p2.second < p2.first * p1.second; });

        long long ans = 0LL;
        long long s = 0LL;
        for (auto &[k, d] : comb)
        {
            s += k;
            ans += s * d;
        }
        return ans;
    }
};
// @lc code=end
