/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string stk;
        for (char &c : s)
        {
            if (!stk.empty() && c == stk.back())
                stk.pop_back();
            else
                stk.push_back(c);
        }
        return stk;
    }
};
// @lc code=end
