/*
 * @lc app=leetcode.cn id=2842 lang=cpp
 *
 * [2842] 统计一个字符串的 k 子序列美丽值最大的数目
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int countKSubsequencesWithMaxBeauty(string s, int k)
    {
        vector<int> cnt(26, 0);
        for (char &c : s)
            cnt[c - 'a']++;

        // STL map 会自动按键从小到大排序
        map<int, int> cc;
        for (int &c : cnt)
            if (c)
                cc[-c]++;

        long long ans = 1;
        for (auto &[c, num] : cc)
        {
            if (num >= k)
                return ans * pow(-c, k) % MOD * comb(num, k) % MOD;
            ans = ans * pow(-c, num) % MOD;
            k -= num;
        }
        return 0;
    }
    // 辅函数 - 快速幂
    long long pow(long long x, int n)
    {
        long long res = 1;
        for (; n; n /= 2)
        {
            if (n % 2)
                res = res * x % MOD;
            x = x * x % MOD;
        }
        return res;
    }
    // 辅函数 - 求组合数 C(n,k)
    long long comb(long long n, int k)
    {
        long long res = n;
        for (int i = 2; i <= k; i++)
        {
            n--;
            // n, n-1, n-2,... 中的前 i 个数至少有一个因子 i
            res = res * n / i;
        }
        return res % MOD;
    }
};
// @lc code=end
