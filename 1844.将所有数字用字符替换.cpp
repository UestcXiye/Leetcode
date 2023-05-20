/*
 * @lc app=leetcode.cn id=1844 lang=cpp
 *
 * [1844] 将所有数字用字符替换
 */

// @lc code=start
class Solution
{
private:
    char shift(char c, int x)
    {
        return c + x;
    }

public:
    string replaceDigits(string s)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
            if (i % 2 == 1)
                s[i] = shift(s[i - 1], s[i] - '0');
        return s;
    }
};
// @lc code=end
