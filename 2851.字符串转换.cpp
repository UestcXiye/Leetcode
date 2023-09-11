/*
 * @lc app=leetcode.cn id=2851 lang=cpp
 *
 * [2851] 字符串转换
 */

// @lc code=start

// 矩阵快速幂优化 DP

class Solution
{
public:
    int numberOfWays(string s, string t, long long k)
    {
        int n = s.size();
        int c = kmp_search(s + s.substr(0, n - 1), t);
        vector<vector<long long>> m = {
            {c - 1, c},
            {n - c, n - 1 - c}};
        m = pow(m, k);
        return m[0][s != t];
    }

private:
    // KMP 模板
    vector<int> calc_max_match(string s)
    {
        vector<int> match(s.size());
        int c = 0;
        for (int i = 1; i < s.size(); i++)
        {
            char v = s[i];
            while (c && s[c] != v)
                c = match[c - 1];
            if (s[c] == v)
                c++;
            match[i] = c;
        }
        return match;
    }

    // KMP 模板
    // 返回 text 中出现了多少次 pattern（允许 pattern 重叠）
    int kmp_search(string text, string pattern)
    {
        vector<int> match = calc_max_match(pattern);
        int match_cnt = 0, c = 0;
        for (int i = 0; i < text.size(); i++)
        {
            char v = text[i];
            while (c && pattern[c] != v)
                c = match[c - 1];
            if (pattern[c] == v)
                c++;
            if (c == pattern.size())
            {
                match_cnt++;
                c = match[c - 1];
            }
        }
        return match_cnt;
    }

    const long long MOD = 1e9 + 7;

    // 矩阵乘法
    vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b)
    {
        vector<vector<long long>> c(2, vector<long long>(2));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
        return c;
    }

    // 矩阵快速幂
    vector<vector<long long>> pow(vector<vector<long long>> &a, long long n)
    {
        vector<vector<long long>> res = {{1, 0}, {0, 1}};
        for (; n; n /= 2)
        {
            if (n % 2)
                res = multiply(res, a);
            a = multiply(a, a);
        }
        return res;
    }
};
// @lc code=end
