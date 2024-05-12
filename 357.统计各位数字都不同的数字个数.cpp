/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 统计各位数字都不同的数字个数
 */

// @lc code=start

// 递归

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        function<int(int)> dfs = [&](int i) -> int
        {
            if (i == 0)
                return 1;
            if (i == 1)
                return 10;
            return dfs(i - 1) + (dfs(i - 1) - dfs(i - 2)) * (10 - (i - 1));
        };
        return dfs(n);
    }
};

// 动态规划

// class Solution
// {
// public:
//     int countNumbersWithUniqueDigits(int n)
//     {
//         if (n == 0)
//             return 1;
//         if (n == 1)
//             return 10;
//         // dp[i] 表示 i 位数字都不同的数字 x 的个数
//         vector<int> dp(n + 1, 0);
//         // 初始化
//         dp[0] = 1;
//         dp[1] = 10;
//         // 状态转移
//         for (int i = 2; i <= n; i++)
//             dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * (10 - (i - 1));
//         return dp[n];
//     }
// };
// @lc code=end
