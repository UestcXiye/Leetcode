/*
 * @lc app=leetcode.cn id=2827 lang=cpp
 *
 * [2827] 范围中美丽整数的数目
 */

// @lc code=start

// 数位 DP

class Solution
{
public:
    int numberOfBeautifulIntegers(int low, int high, int k)
    {
        return countBIfrom1toN(high, k) - countBIfrom1toN(low - 1, k);
    }
    // 辅函数 - 计算 [1, n] 的美丽整数的数目
    int countBIfrom1toN(int n, int k)
    {
        string s = to_string(n);
        int len = s.length(), memo[len][k + 1][len * 2 + 1];
        memset(memo, -1, sizeof(memo)); // -1 表示没有计算过

        function<int(int, int, int, bool, bool)> dfs;
        // 返回从 i 开始填数字，已经构造的数位，模 k 等于 val，能构造出的美丽整数的数目
        // diff: 奇数数位的数目 - 偶数数位的数目
        // is_limit 表示前面填的数字是否都是 n 对应位上的，
        // 如果为 true，那么当前位至多为 s[i]，否则至多为 9
        // is_num 表示前面是否填了数字（是否跳过），
        // 如果为 true，那么当前位可以从 0 开始，否则当前位可以跳过，或者从 1 开始填数字
        dfs = [&](int i, int val, int diff, bool is_limit, bool is_num) -> int
        {
            if (i == len)
            {
                // 找到了一个合法数字
                return is_num && val == 0 && diff == len;
            }
            if (!is_limit && is_num && memo[i][val][diff] != -1)
                return memo[i][val][diff];
            int res = 0;
            if (!is_num)
            {
                // 可以跳过当前数位
                res = dfs(i + 1, val, diff, false, false);
            }
            // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
            int up = is_limit ? s[i] - '0' : 9;
            // 枚举要填入的数字 d
            for (int d = 1 - is_num; d <= up; d++)
                res += dfs(i + 1, (val * 10 + d) % k, diff + d % 2 * 2 - 1, is_limit && d == up, true);
            if (!is_limit && is_num)
                memo[i][val][diff] = res; // 记忆化
            return res;
        };
        return dfs(0, 0, len, true, false);
    }
};
// @lc code=end
