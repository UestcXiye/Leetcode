/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution
{
private:
    string trans(string s)
    {
        string str;
        for (char &c : s)
        {
            if (c == '#')
            {
                if (!str.empty())
                    str.pop_back();
            }
            else
            {
                str.push_back(c);
            }
        }
        return str;
    }

public:
    bool backspaceCompare(string s, string t)
    {
        return trans(s) == trans(t);
    }
};
// @lc code=end
