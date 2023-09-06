/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
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
        // 状态矩阵，并初始化
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // dp[i,j]: word1到位置i为止，和word2到位置j为止，最少需要几步编辑
        for (int i = 0; i <= len1; i++)
            for (int j = 0; j <= len2; j++)
            {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
            }
        // 状态转移
        for (int i = 1; i <= len1; i++)
            for (int j = 1; j <= len2; j++)
            {
                // 当第i位和第j位对应的字符相同时，无需操作
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                // 当二者对应的字符不同时，
                // 修改的消耗是dp[i-1][j-1]+1
                // 插入i位置/删除j位置的消耗是dp[i][j-1]+1，
                // 插入j位置/删除i位置的消耗是dp[i-1][j]+1
                else
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            }
        return dp[len1][len2];
    }
};
// @lc code=end
