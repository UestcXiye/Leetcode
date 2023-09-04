/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// class Solution
// {
// public:
//     int climbStairs(int n)
//     {
//         // 特判
//         if (n == 1)
//             return 1;
//         if (n == 2)
//             return 2;
//         // 状态数组
//         vector<int> dp(n + 1, 0);
//         // 初始化
//         dp[1] = 1, dp[2] = 2;
//         // 状态转移
//         for (int i = 3; i <= n; i++)
//             dp[i] = dp[i - 1] + dp[i - 2]; // 状态转移方程
//         return dp[n];
//     }
// };

// 空间压缩
class Solution
{
public:
    int climbStairs(int n)
    {
        // 特判
        if (n <= 2)
            return n;
        int pre2 = 1, pre1 = 2, cur;
        for (int i = 3; i <= n; i++)
        {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};
//  @lc code=end
