/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 *
 * [1553] 吃掉 N 个橘子的最少天数
 */

// @lc code=start
class Solution
{
private:
    unordered_map<int, int> memo;

public:
    int minDays(int n)
    {
        function<int(int)> dfs = [&](int i) -> int
        {
            if (i <= 1)
                return i;
            if (memo.count(i))
                return memo[i];
            int day1 = minDays(i / 2) + i % 2;
            int day2 = minDays(i / 3) + i % 3;
            return memo[i] = min(day1, day2) + 1;
        };
        return dfs(n);
    }
};
// @lc code=end
