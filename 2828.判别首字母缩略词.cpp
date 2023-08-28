/*
 * @lc app=leetcode.cn id=2828 lang=cpp
 *
 * [2828] 判别首字母缩略词
 */

// @lc code=start
class Solution
{
public:
    bool isAcronym(vector<string> &words, string s)
    {
        int n = words.size(), len = s.size();
        if (n != len)
            return false;
        for (int i = 0; i < n; i++)
        {
            if (words[i].front() != s[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
