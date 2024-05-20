/*
 * @lc app=leetcode.cn id=3154 lang=cpp
 *
 * [3154] 到达第 K 级台阶的方案数
 */

// @lc code=start
class Solution
{
private:
    unordered_map<long long, int> memo;

public:
    int waysToReachStair(int k)
    {
        // 当前位于台阶 i，已经使用了 jump 次第二种操作，preDown：上一次操作是否为操作一
        function<int(int, int, bool)> dfs = [&](int i, int jump, bool preDown) -> int
        {
            if (i > k + 1)
                return 0;

            long long state = (long long)i << 32 | jump << 1 | preDown;
            if (memo.contains(state))
                return memo[state];

            int res = 0;
            if (i == k)
                res++;
            if (i != 0 && preDown == false)
            { // 操作一
                res += dfs(i - 1, jump, true);
            }
            res += dfs(i + (1 << jump), jump + 1, false); // 操作二

            memo[state] = res; // 记忆化
            return res;
        };
        // 从台阶 1 开始，一开始 jump 为 0，前一次操作不为操作二
        return dfs(1, 0, false);
    }
};
// @lc code=end
