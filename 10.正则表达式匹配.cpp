/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        // 状态矩阵
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // dp[i,j]: 表示以i截止的字符串是否可以被以j截止的正则表达式匹配
        //  初始化
        dp[0][0] = true;
        // 在匹配0次的情况下，浪费一个字符+星号的组合，没有匹配任何s中的字符
        for (int i = 1; i <= n; i++)
            if (p[i - 1] == '*') //'*'匹配零个或多个前面的那一个元素
                dp[0][i] = dp[0][i - 2];
        // 状态转移
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] != '*') // 当前p匹配的字符不是'*'
                {
                    if (match(s[i - 1], p[j - 1]) == true) // 当前s匹配的字符和p匹配的字符相符合
                        dp[i][j] = dp[i - 1][j - 1];
                    else // 当前s匹配的字符和p匹配的字符不相符合，dp[i,j]=false
                        dp[i][j] = false;
                }
                else // 当前p匹配的字符为'*'
                {
                    // 当前s匹配的字符和p匹配的p中一个字符+星号的组合相匹配，
                    // 要么跳过一个字符+星号的组合，要么看dp[i-1][j]是否为true，或运算连接
                    if (match(s[i - 1], p[j - 2]) == true)
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    else // 当前s匹配的字符和p中一个字符+星号的组合不相匹配，跳过该组合
                        dp[i][j] = dp[i][j - 2];
                }
            }
        return dp[m][n];
    }
    // 辅函数
    bool match(char &sc, char &pc)
    {
        //'.'匹配任意单个字符，故一定匹配成功
        if (pc == '.')
            return true;
        // 不然看s字符和p字符是否相同
        return sc == pc;
    }
};
// @lc code=end
