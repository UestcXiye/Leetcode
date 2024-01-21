/*
 * @lc app=leetcode.cn id=2376 lang=cpp
 *
 * [2376] 统计特殊整数
 */

// @lc code=start
class Solution
{
public:
    int countSpecialNumbers(int n)
    {
        string s = to_string(n);
        int len = s.length(), memo[len][1 << 10];
        memset(memo, -1, sizeof(memo)); // -1 表示没有计算过

        function<int(int, int, bool, bool)> dfs;
        // 返回从 i 开始填数字，前面填的数字集合是 mask，能构造出的特殊整数的数目
        // is_limit 表示前面填的数字是否都是 n 对应位上的，
        // 如果为 true，那么当前位至多为 s[i]，否则至多为 9
        // is_num 表示前面是否填了数字（是否跳过），
        // 如果为 true，那么当前位可以从 0 开始，否则当前位可以跳过，或者从 1 开始填数字
        dfs = [&](int i, int mask, bool is_limit, bool is_num) -> int
        {
            if (i == len)
            {
                // 找到了一个合法数字
                return is_num;
            }
            if (!is_limit && is_num && memo[i][mask] != -1)
                return memo[i][mask];
            int res = 0;
            if (!is_num)
            {
                // 可以跳过当前数位
                res = dfs(i + 1, mask, false, false);
            }
            // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
            int up = is_limit ? s[i] - '0' : 9;
            // 枚举要填入的数字 d
            for (int d = 1 - is_num; d <= up; d++)
                if ((mask >> d & 1) == 0)
                {
                    // d 不在 mask 中
                    res += dfs(i + 1, mask | (1 << d), is_limit && d == up, true);
                }
            if (!is_limit && is_num)
                memo[i][mask] = res; // 记忆化
            return res;
        };

        return dfs(0, 0, true, false);
    }
};
// @lc code=end
