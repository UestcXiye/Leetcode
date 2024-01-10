/*
 * @lc app=leetcode.cn id=10038 lang=cpp
 *
 * [10038] 执行操作后的最大分割数量
 */

// @lc code=start

// 记忆化搜索 + 记录字符集合

class Solution
{
public:
    int maxPartitionsAfterOperations(string s, int k)
    {
        // 特判
        if (k == 26)
            return 1;

        unordered_map<long long, int> memo;
        function<int(int, int, bool)> dfs = [&](int i, int mask, bool changed) -> int
        {
            if (i == s.length())
                return 1;

            long long args_mask = (long long)i << 32 | mask << 1 | changed;
            auto it = memo.find(args_mask);
            if (it != memo.end())
            { // 之前计算过
                return it->second;
            }

            int res;
            // 不改 s[i]
            int bit = 1 << (s[i] - 'a');
            int new_mask = mask | bit;
            if (__builtin_popcount(new_mask) > k)
            {
                // 分割出一个子串，这个子串的最后一个字母在 i-1
                // s[i] 作为下一段的第一个字母，也就是 bit 作为下一段的 mask 的初始值
                res = dfs(i + 1, bit, changed) + 1;
            }
            else
            { // 不分割
                res = dfs(i + 1, new_mask, changed);
            }

            if (!changed)
            {
                // 枚举把 s[i] 改成 a,b,c,...,z
                for (int j = 0; j < 26; j++)
                {
                    new_mask = mask | (1 << j);
                    if (__builtin_popcount(new_mask) > k)
                    {
                        // 分割出一个子串，这个子串的最后一个字母在 i-1
                        // j 作为下一段的第一个字母，也就是 1<<j 作为下一段的 mask 的初始值
                        res = max(res, dfs(i + 1, 1 << j, true) + 1);
                    }
                    else
                    { // 不分割
                        res = max(res, dfs(i + 1, new_mask, true));
                    }
                }
            }

            return memo[args_mask] = res; // 记忆化
        };
        return dfs(0, 0, false);
    }
};
// @lc code=end
