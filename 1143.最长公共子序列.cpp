/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.size(), len2 = text2.size();
        // 状态数组，并初始化
        //  dp[i][j]表示到text1的位置i为止、到text2的位置j为止、最长的公共子序列长度
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // 状态转移
        for (int i = 1; i <= len1; i++)
            for (int j = 1; j <= len2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        return dp[len1][len2];
    }
};
// @lc code=end
