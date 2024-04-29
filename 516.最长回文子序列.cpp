/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start

// 记忆化搜索

// class Solution
// {
// public:
//     int longestPalindromeSubseq(string s)
//     {
//         int n = s.length();
//         int memo[n][n];
//         memset(memo, -1, sizeof(memo)); // -1 表示还没有计算过

//         function<int(int, int)> dfs = [&](int i, int j) -> int
//         {
//             if (i > j)
//                 return 0;
//             if (i == j)
//                 return 1;
//             int &res = memo[i][j];
//             if (res != -1)
//                 return res;
//             if (s[i] == s[j])
//             {
//                 res = dfs(i + 1, j - 1) + 2;
//                 return res;
//             }
//             res = max(dfs(i + 1, j), dfs(i, j - 1));
//             return res;
//         };

//         return dfs(0, n - 1);
//     }
// };

// 动态规划

// class Solution
// {
// public:
//     int longestPalindromeSubseq(string s)
//     {
//         int n = s.length();
//         // dp[i][j] 表示 s[i...j] 的最长回文子序列长度
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         // 初始化
//         for (int i = 0; i < n; i++)
//             dp[i][i] = 1;
//         // 状态转移
//         for (int i = n - 1; i >= 0; i--)
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (s[i] == s[j])
//                     dp[i][j] = dp[i + 1][j - 1] + 2;
//                 else
//                     dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//             }
//         return dp[0][n - 1];
//     }
// };

// 动态规划：空间优化

// class Solution
// {
// public:
//     int longestPalindromeSubseq(string s)
//     {
//         int n = s.length();
//         // 滚动数组
//         vector<int> dp(n, 0);
//         // 状态转移
//         for (int i = n - 1; i >= 0; i--)
//         {
//             dp[i] = 1;
//             int pre = 0; // dp[i+1][i]
//             for (int j = i + 1; j < n; j++)
//             {
//                 int tmp = dp[j];
//                 if (s[i] == s[j])
//                     dp[j] = pre + 2;
//                 else
//                     dp[j] = max(dp[j], dp[j - 1]);
//                 pre = tmp;
//             }
//         }
//         return dp[n - 1];
//     }
// };

// 转化成 LCS 问题

class Solution
{
private:
    int LCS(string s, string t)
    {
        int n = s.length(), m = t.length();
        int memo[n][m];
        memset(memo, -1, sizeof(memo)); // -1 表示没有访问过
        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i < 0 || j < 0)
                return 0;
            int &res = memo[i][j];
            if (res != -1)
                return res;
            if (s[i] == t[j])
                return res = dfs(i - 1, j - 1) + 1;
            return res = max(dfs(i - 1, j), dfs(i, j - 1));
        };
        return dfs(n - 1, m - 1);
    }

public:
    int longestPalindromeSubseq(string s)
    {
        string s_rev(s.rbegin(), s.rend());
        return LCS(s, s_rev);
    }
};
// @lc code=end
