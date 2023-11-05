/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int count = 0, balance = 0;
        for (const char &c : s)
        {
            if (c == 'R')
                balance++;
            else
                balance--;
            if (balance == 0)
                count++;
        }
        return count;
    }
};
// @lc code=end
