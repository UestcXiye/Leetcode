/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (const string &token : tokens)
        {
            if (token == "+")
            {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(x + y);
            }
            else if (token == "-")
            {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y - x);
            }
            else if (token == "*")
            {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(x * y);
            }
            else if (token == "/")
            {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y / x);
            }
            else
            {
                int num = stoi(token);
                stk.push(num);
            }
        }
        return stk.top();
    }
};
// @lc code=end
