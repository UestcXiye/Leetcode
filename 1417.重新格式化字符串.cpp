/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */

// @lc code=start
class Solution
{
public:
    string reformat(string s)
    {
        stack<char> stNum, stChar;
        for (const auto &c : s)
        {
            if (c >= 'a' && c <= 'z')
                stChar.push(c);
            else
                stNum.push(c);
        }
        if (abs(int(stNum.size()) - int(stChar.size())) > 1)
            return "";
        string res;
        while (stNum.size() && stChar.size())
        {
            if (stNum.size() > stChar.size())
            {
                res += stNum.top();
                res += stChar.top();
            }
            else
            {
                res += stChar.top();
                res += stNum.top();
            }
            stNum.pop();
            stChar.pop();
        }
        if (stNum.size())
            res += stNum.top();
        else if (stChar.size())
            res += stChar.top();
        return res;
    }
};
// @lc code=end
