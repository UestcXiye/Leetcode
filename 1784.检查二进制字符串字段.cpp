/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        bool tip = false;
        for (char c : s)
        {
            if (c == '0')
                tip = true;
            else if (c == '1' && tip)
                return false;
        }
        return true;
    }
};
// @lc code=end
