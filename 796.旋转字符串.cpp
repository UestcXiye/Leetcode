/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        for (int i = 0; i < s.size(); i++)
        {
            string trans = s.substr(i, s.size() - i);
            trans += s.substr(0, i);
            if (trans == goal)
                return true;
        }
        return false;
    }
};
// @lc code=end
