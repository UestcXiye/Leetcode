/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start

// 递归

// class Solution
// {
// public:
//     int tribonacci(int n)
//     {
//         if (n == 0)
//             return 0;
//         if (n == 1 || n == 2)
//             return 1;
//         return tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
//     }
// };

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        vector<int> dp(n + 1, 0);
        // 初始化
        dp[1] = 1, dp[2] = 1;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        return dp[n];
    }
};
// @lc code=end
