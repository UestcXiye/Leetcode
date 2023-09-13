/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
private:
    bool match(char &c1, char &c2)
    {
        if ((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']'))
            return true;
        else
            return false;
    }

public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);
            else
            {
                if (stk.empty())
                    return false;
                char c = stk.top();
                if (match(c, s[i]))
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};
// @lc code=end
