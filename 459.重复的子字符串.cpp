/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        for (int len = 1; len <= n / 2; len++)
        {
            if (n % len == 0)
            {
                bool match = true;
                for (int i = len; i < n; i++)
                {
                    if (s[i] != s[i - len])
                    {
                        match = false;
                        break;
                    }
                }
                if (match)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
