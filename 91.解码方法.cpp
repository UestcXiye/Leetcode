/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        // 特判（s 只包含数字，并且可能包含前导零）
        if (s.empty() || s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;
        int n = s.size(), pre = s[0] - '0';
        // 状态矩阵，并初始化（每个数字均可映射成一个字母）
        vector<int> dp(n + 1, 1);
        // 状态转移
        for (int i = 2; i <= n; i++)
        {
            int cur = s[i - 1] - '0';
            if (cur == 0 && (pre != 1 && pre != 2))
                return 0;
            if (pre == 1 || (pre == 2 && cur <= 6)) // 当前数字为10~26
            {
                if (cur != 0) // cur不为0，则当前数字可以拆分，方法数累加
                    dp[i] = dp[i - 2] + dp[i - 1];
                else // 当前数字为10或20，不可拆分，只有一种映射，解码方法不增加
                    dp[i] = dp[i - 2];
            }
            else // 当前数字为1~9，只有一种映射，解码方法不增加
                dp[i] = dp[i - 1];
            pre = cur;
        }
        return dp[n];
    }
};
// @lc code=end
