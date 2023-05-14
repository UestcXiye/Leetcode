/*
 * @lc app=leetcode.cn id=2278 lang=cpp
 *
 * [2278] 字母在字符串中的百分比
 */

// @lc code=start
class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        int count = 0;
        for (char c : s)
        {
            if (c == letter)
                count++;
        }
        return count * 100 / s.size();
    }
};
// @lc code=end
