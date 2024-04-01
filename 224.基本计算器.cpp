/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n)
        {
            if (s[i] == ' ')
                i++;
            else if (s[i] == '+')
            {
                sign = ops.top();
                i++;
            }
            else if (s[i] == '-')
            {
                sign = -ops.top();
                i++;
            }
            else if (s[i] == '(')
            {
                ops.push(sign);
                i++;
            }
            else if (s[i] == ')')
            {
                ops.pop();
                i++;
            }
            else
            {
                long num = 0;
                while (i < n && isdigit(s[i]))
                {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};
// @lc code=end
