/*
 * @lc app=leetcode.cn id=3337 lang=cpp
 *
 * [3337] 字符串转换后的长度 II
 */

// @lc code=start
class Solution
{
private:
    static constexpr int MOD = 1e9 + 7;
    static constexpr int SIZE = 26;

    using Matrix = array<array<int, SIZE>, SIZE>;

    // 返回矩阵 a 和矩阵 b 相乘的结果
    Matrix mul(Matrix &a, Matrix &b)
    {
        Matrix c{};
        for (int i = 0; i < SIZE; i++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                if (a[i][k] == 0)
                    continue;
                for (int j = 0; j < SIZE; j++)
                    c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % MOD;
            }
        }
        return c;
    }

    // 返回 n 个矩阵 a 相乘的结果
    Matrix pow(Matrix a, int n)
    {
        Matrix res = {};
        for (int i = 0; i < SIZE; i++)
            res[i][i] = 1; // 单位矩阵
        while (n)
        {
            if (n & 1)
                res = mul(res, a);
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int> &nums)
    {
        Matrix m{};
        for (int i = 0; i < SIZE; i++)
            for (int j = i + 1; j <= i + nums[i]; j++)
                m[i][j % SIZE] = 1;

        m = pow(m, t);

        int cnt[SIZE]{};
        for (char &c : s)
            cnt[c - 'a']++;

        long long ans = 0;
        for (int i = 0; i < SIZE; i++)
        {
            // m 第 i 行的和就是 f[t][i]
            ans += reduce(m[i].begin(), m[i].end(), 0LL) * cnt[i];
        }
        return ans % MOD;
    }
};
// @lc code=end
