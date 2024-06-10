/*
 * @lc app=leetcode.cn id=3174 lang=cpp
 *
 * [3174] 清除数字
 */

// @lc code=start
class Solution
{
public:
    string clearDigits(string s)
    {
        stack<char> stk;
        for (char &c : s)
        {
            if (isdigit(c))
                stk.pop();
            else
                stk.push(c);
        }
        string ans;
        while (!stk.empty())
        {
            ans.insert(ans.begin(), stk.top());
            stk.pop();
        }
        return ans;
    }
};
// @lc code=end
