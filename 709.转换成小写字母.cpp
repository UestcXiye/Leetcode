/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution
{
public:
    string toLowerCase(string s)
    {
        for (char &c : s)
            if (isupper(c))
                c = tolower(c);
        return s;
    }
};
// @lc code=end
