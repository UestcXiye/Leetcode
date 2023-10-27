/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        // 特判
        if (len1 + len2 != len3)
            return false;
        // 状态矩阵
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        // 初始化
        dp[0][0] = true;
        // 状态转移
        for (int i = 0; i <= len1; i++)
            for (int j = 0; j <= len2; j++)
            {
                int index = i + j - 1;
                if (i > 0)
                    dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[index]);
                if (j > 0)
                    dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[index]);
            }
        return dp[len1][len2];
    }
};
// @lc code=end
