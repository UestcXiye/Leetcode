/*
 * @lc app=leetcode.cn id=3304 lang=cpp
 *
 * [3304] 找出第 K 个字符 I
 */

// @lc code=start
class Solution
{
public:
    char kthCharacter(int k)
    {
        string s = "a";
        while (s.length() < k)
        {
            int len = s.length();
            for (int i = 0; i < len; i++)
                s += s[i] + 1;
        }
        return s[k - 1];
    }
};
// @lc code=end
