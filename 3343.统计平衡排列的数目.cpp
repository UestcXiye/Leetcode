/*
 * @lc app=leetcode.cn id=3343 lang=cpp
 *
 * [3343] 统计平衡排列的数目
 */

// @lc code=start
const int MOD = 1'000'000'007;
const int MX = 41;

long long F[MX];     // F[i] = i!
long long INV_F[MX]; // INV_F[i] = i!^-1

long long pow(long long x, int n)
{
    long long res = 1;
    for (; n; n /= 2)
    {
        if (n % 2)
        {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

auto init = []
{
    F[0] = 1;
    for (int i = 1; i < MX; i++)
    {
        F[i] = F[i - 1] * i % MOD;
    }
    INV_F[MX - 1] = pow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--)
    {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
}();

class Solution
{
public:
    int countBalancedPermutations(string num)
    {
        int cnt[10];
        int total = 0;
        for (char c : num)
        {
            cnt[c - '0']++;
            total += c - '0';
        }

        if (total % 2)
            return 0;

        // 原地求前缀和
        partial_sum(cnt, cnt + 10, cnt);

        int n = num.size(), n1 = n / 2;
        vector<vector<vector<int>>> memo(10, vector(n1 + 1, vector<int>(total / 2 + 1, -1))); // -1 表示没有计算过
        auto dfs = [&](auto &dfs, int i, int left1, int left_s) -> int
        {
            if (i < 0)
            {
                return left_s == 0;
            }
            int &res = memo[i][left1][left_s]; // 注意这里是引用
            if (res != -1)
            { // 之前计算过
                return res;
            }
            res = 0;
            int c = cnt[i] - (i ? cnt[i - 1] : 0);
            int left2 = cnt[i] - left1;
            for (int k = max(c - left2, 0); k <= min(c, left1) && k * i <= left_s; k++)
            {
                int r = dfs(dfs, i - 1, left1 - k, left_s - k * i);
                res = (res + r * INV_F[k] % MOD * INV_F[c - k]) % MOD;
            }
            return res;
        };
        return F[n1] * F[n - n1] % MOD * dfs(dfs, 9, n1, total / 2) % MOD;
    }
};
// @lc code=end
