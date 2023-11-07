/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start
class Solution
{
public:
    int maxDepth(string s)
    {
        int max_depth = 0;
        stack<char> stk;
        for (const char &c : s)
        {
            if (c == '(')
            {
                stk.push(c);
                max_depth = max(max_depth, (int)stk.size());
            }
            else if (c == ')')
                stk.pop();
        }
        return max_depth;
    }
};
// @lc code=end
