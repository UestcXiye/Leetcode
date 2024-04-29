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

class Solution
{
public:
    int longestCommonSubsequence(string s, string t)
    {
        // 特判
        if (s.empty() || t.empty())
            return 0;
        int n = s.size(), m = t.size();
        //  dp[i][j]表示到s的位置i为止、到t的位置j为止、最长的公共子序列长度
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        // state
        vector<vector<int>> state(n + 1, vector<int>(m + 1));
        // 初始化
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;
        // 状态转移
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    state[i][j] = 0; // 为了后面回溯，作为公共子序列的判定
                }
                else if (dp[i - 1][j] >= dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    state[i][j] = 1; // 为了后面向上回溯，向上寻找子序列的判定
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    state[i][j] = 2; // 为了后面向左回溯，向左寻找子序列的判定
                }
            }
        int lscLen = dp[n][m];
        string lsc = string(lscLen, 0);
        int i = n, j = m, k = lscLen - 1;
        while (k >= 0)
        {
            if (state[i][j] == 0)
            {
                lsc[k--] = s[i - 1];
                i--;
                j--;
            }
            else if (state[i][j] == 1)
                i--;
            else
                j--;
        }
        return lscLen;
    }
};

// 动态规划：空间优化

// class Solution
// {
// public:
//     int longestCommonSubsequence(string s, string t)
//     {
//         int n = s.length(), m = t.length(), dp[2][m + 1];
//         memset(dp, 0, sizeof(dp));
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < m; j++)
//             {
//                 if (s[i] == t[j])
//                     dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
//                 else
//                     dp[(i + 1) % 2][j + 1] = max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]);
//             }
//         return dp[n % 2][m];
//     }
// };

// @lc code=end
