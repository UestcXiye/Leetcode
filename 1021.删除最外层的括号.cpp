/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        stack<char> stk;
        string ans;
        for (const char &c : s)
        {
            if (c == ')')
                stk.pop();
            if (!stk.empty())
                ans += c;
            if (c == '(')
                stk.push(c);
        }
        return ans;
    }
};
// @lc code=end
