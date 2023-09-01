/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
class Solution
{
public:
    string modifyString(string s)
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '?')
            {
                for (char temp = 'a'; temp <= 'z'; temp++)
                {
                    if (i == 0)
                    {
                        if (temp != s[i + 1])
                        {
                            s[i] = temp;
                            break;
                        }
                    }
                    else if (i == s.size() - 1)
                    {
                        if (temp != s[i - 1])
                        {
                            s[i] = temp;
                            break;
                        }
                    }
                    else
                    {
                        if (temp != s[i - 1] && temp != s[i + 1])
                        {
                            s[i] = temp;
                            break;
                        }
                    }
                }
            }
        return s;
    }
};
// @lc code=end
