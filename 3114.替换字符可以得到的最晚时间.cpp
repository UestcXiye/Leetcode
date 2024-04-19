/*
 * @lc app=leetcode.cn id=3114 lang=cpp
 *
 * [3114] 替换字符可以得到的最晚时间
 */

// @lc code=start
class Solution
{
public:
    string findLatestTime(string s)
    {
        int i = 0;
        if (s[0] == '?' && s[1] == '?')
        {
            s[0] = s[1] = '1';
            i += 3;
        }
        for (; i < 5; i++)
            if (s[i] == '?')
            {
                if (i == 0)
                {
                    if (s[1] < '2')
                        s[i] = '1';
                    else
                        s[i] = '0';
                }
                else if (i == 1)
                {
                    if (s[0] == '1')
                        s[i] = '1';
                    else
                        s[i] = '9';
                }
                else if (i == 3)
                    s[i] = '5';
                else if (i == 4)
                    s[i] = '9';
            }
        return s;
    }
};
// @lc code=end
