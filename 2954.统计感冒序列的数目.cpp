/*
 * @lc app=leetcode.cn id=2954 lang=cpp
 *
 * [2954] 统计感冒序列的数目
 */

// @lc code=start

const static int MOD = 1e9 + 7;
const static int MX = 1e5;

long long q_pow(long long x, int n)
{
    long long res = 1;
    for (; n > 0; n /= 2)
    {
        if (n % 2)
        {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

// 组合数模板
long long fac[MX], inv_fac[MX];

auto init = []
{
    fac[0] = 1;
    for (int i = 1; i < MX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[MX - 1] = q_pow(fac[MX - 1], MOD - 2);
    for (int i = MX - 1; i > 0; i--)
    {
        inv_fac[i - 1] = inv_fac[i] * i % MOD;
    }
    return 0;
}();

long long comb(int n, int k)
{
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
}

class Solution
{
public:
    int numberOfSequence(int n, vector<int> &sick)
    {
        int m = sick.size();
        int total = n - m;
        long long ans = comb(total, sick[0]) * comb(total - sick[0], n - sick.back() - 1) % MOD;
        total -= sick[0] + n - sick.back() - 1;
        int e = 0;
        for (int i = 0; i < m - 1; i++)
        {
            int k = sick[i + 1] - sick[i] - 1;
            if (k)
            {
                e += k - 1;
                ans = ans * comb(total, k) % MOD;
                total -= k;
            }
        }
        return ans * q_pow(2, e) % MOD;
    }
};
// @lc code=end
