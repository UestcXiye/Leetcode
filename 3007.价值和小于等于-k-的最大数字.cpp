/*
 * @lc app=leetcode.cn id=3007 lang=cpp
 *
 * [3007] 价值和小于等于 K 的最大数字
 */

// @lc code=start

// 二分查找 + 数位 DP

class Solution
{
public:
    long long findMaximumNumber(long long k, int x)
    {
        long long left = 0, right = (k + 1) << x;
        while (left + 1 < right)
        {
            long long mid = left + (right - left) / 2;
            if (countDigitOne(mid, x) <= k)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
    // 辅函数 - 计算所有小于等于 num 的非负整数中的价值总和
    // 一个整数 num 的价值是满足 i % x == 0 且 s[i] 是 1 的 i 的数目
    long long countDigitOne(long long num, int x)
    {
        int m = 64 - __builtin_clzll(num);
        vector<vector<long long>> memo(m, vector<long long>(m + 1, -1));
        function<long long(int, int, bool)> dfs = [&](int i, int cnt1, bool is_limit) -> long long
        {
            if (i < 0)
                return cnt1;
            if (!is_limit && memo[i][cnt1] >= 0)
                return memo[i][cnt1];
            int up = is_limit ? num >> i & 1 : 1;
            long long res = 0;
            for (int d = 0; d <= up; d++) // 枚举要填入的数字 d
                res += dfs(i - 1, cnt1 + (d == 1 && (i + 1) % x == 0), is_limit && d == up);
            if (!is_limit)
                memo[i][cnt1] = res;
            return res;
        };
        return dfs(m - 1, 0, true);
    }
};
// @lc code=end
