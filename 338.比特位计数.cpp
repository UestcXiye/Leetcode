/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start

// 位运算

// class Solution
// {
// public:
//     vector<int> countBits(int n)
//     {
//         vector<int> ans(n + 1, 0);
//         for (int i = 0; i <= n; i++)
//         {
//             int num = i, count = 0;
//             while (num)
//             {
//                 count += num & 01;
//                 num >>= 1;
//             }
//             ans[i] = count;
//         }
//         return ans;
//     }
// };

// 动态规划

class Solution
{
public:
    vector<int> countBits(int n)
    {
        // 状态数组，并初始化
        vector<int> dp(n + 1, 0);
        // 状态转移
        for (int i = 1; i <= n; i++)
        {
            // 对于第 i 个数字，
            // 如果它二进制的最后一位为 1,那么它含有 1 的个数则为 dp[i - 1] + 1
            // 如果它二进制的最后一位为 0，那么它含有 1 的个数和其算术右移结果相同
            if (i & 01)
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i >> 1];
            // 等价于dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }
};
// @lc code=end
