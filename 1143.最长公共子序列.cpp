/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start

// 记忆化搜索

// class Solution
// {
// public:
//     int longestCommonSubsequence(string s, string t)
//     {
//         int n = s.length(), m = t.length();
//         int memo[n][m];
//         memset(memo, -1, sizeof(memo)); // -1 表示没有访问过
//         function<int(int, int)> dfs = [&](int i, int j) -> int
//         {
//             if (i < 0 || j < 0)
//                 return 0;
//             int &res = memo[i][j];
//             if (res != -1)
//                 return res;
//             if (s[i] == t[j])
//                 return res = dfs(i - 1, j - 1) + 1;
//             return res = max(dfs(i - 1, j), dfs(i, j - 1));
//         };
//         return dfs(n - 1, m - 1);
//     }
// };

// 动态规划

// class Solution
// {
// public:
//     int longestCommonSubsequence(string text1, string text2)
//     {
//         // 特判
//         if (text1.empty() || text2.empty())
//             return 0;
//         int len1 = text1.size(), len2 = text2.size();
//         // 状态数组，并初始化
//         //  dp[i][j]表示到text1的位置i为止、到text2的位置j为止、最长的公共子序列长度
//         vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
//         // 状态转移
//         for (int i = 1; i <= len1; i++)
//             for (int j = 1; j <= len2; j++)
//             {
//                 if (text1[i - 1] == text2[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 else
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         return dp[len1][len2];
//     }
// };

// 动态规划：空间优化

class Solution
{
public:
    int longestCommonSubsequence(string s, string t)
    {
        int n = s.length(), m = t.length(), dp[2][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (s[i] == t[j])
                    dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
                else
                    dp[(i + 1) % 2][j + 1] = max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]);
            }
        return dp[n % 2][m];
    }
};

// @lc code=end
