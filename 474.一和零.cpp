/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution // 多维费用的0-1 背包问题
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int size = strs.size();
        int dp[size + 1][m + 1][n + 1]; // 状态数组
        // 初始化
        memset(dp, 0, sizeof(dp));
        // 状态转移
        for (int i = 1; i <= size; i++)
        {
            auto [count0, count1] = count(strs[i - 1]);
            for (int j = 0; j <= m; j++)     // j可以从0开始，因为strs里有的元素不含'0'
                for (int k = 0; k <= n; k++) // k可以从0开始，因为strs里有的元素不含'1'
                {
                    if (j >= count0 && k >= count1)
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - count0][k - count1] + 1);
                    else
                        dp[i][j][k] = dp[i - 1][j][k];
                }
        }
        return dp[size][m][n];
    }
    // 辅函数
    pair<int, int> count(string &str)
    {
        int count0 = 0, count1 = 0;
        for (char &c : str)
        {
            if (c == '1')
                count1++;
            else
                count0++;
        }
        return pair<int, int>(count0, count1);
    }
};
// 空间压缩
// class Solution // 多维费用的0-1 背包问题
// {
// public:
//     int findMaxForm(vector<string> &strs, int m, int n)
//     {
//         // 状态数组，并初始化
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         // 状态转移
//         for (string &str : strs)
//         {
//             auto [count0, count1] = count(str);
//             for (int i = m; i >= count0; i--)
//                 for (int j = n; j >= count1; j--)
//                     dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1); // 状态转移方程
//         }
//         return dp[m][n];
//     }
//     // 辅函数
//     pair<int, int> count(string &str)
//     {
//         int count0 = 0, count1 = 0;
//         for (char &c : str)
//         {
//             if (c == '1')
//                 count1++;
//             else
//                 count0++;
//         }
//         return pair<int, int>(count0, count1);
//     }
// };
// @lc code=end
