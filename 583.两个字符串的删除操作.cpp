/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // 特判
        if (word1.empty())
            return word2.size();
        if (word2.empty())
            return word1.size();
        int len1 = word1.size(), len2 = word2.size();
        // 状态矩阵
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // dp[i][j]: 使 word1[0:i] 和 word2[0:j] 相同的最少删除操作次数
        //  初始化
        // word2为空，为使一致，需删除word1的所有字符
        for (int i = 0; i <= len1; i++)
            dp[i][0] = i;
        // word1为空，为使一致，需删除word2的所有字符
        for (int j = 0; j <= len2; j++)
            dp[0][j] = j;
        // 状态转移
        for (int i = 1; i <= len1; i++)
            for (int j = 1; j <= len2; j++)
            {
                if (word1[i - 1] == word2[j - 1]) // 字符相等
                {
                    dp[i][j] = dp[i - 1][j - 1]; // 最少删除操作次数不变
                }
                else // 字符不等
                {    // 删除一个字符，操作次数+1
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        return dp[len1][len2];
    }
};

// class Solution
// {
// public:
//     int minDistance(string word1, string word2)
//     {
//         // 特判
//         if (word1.empty())
//             return word2.size();
//         if (word2.empty())
//             return word1.size();
//         // 求 word1 和 word2 的最长公共子序列的长度
//         int lcs = longestCommonSubsequence(word1, word2);
//         return word1.size() + word2.size() - 2 * lcs;
//     }
//     // 辅函数
//     //  1143.最长公共子序列
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
// @lc code=end
