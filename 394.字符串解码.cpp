/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        int n = s.size(), i = 0;
        stack<string> stk;
        while (i < n)
        {
            char cur = s[i];
            if (isdigit(cur))
            {
                string num = "";
                while (isdigit(s[i]))
                {
                    num.push_back(s[i]);
                    i++;
                }
                stk.push(num);
            }
            else if (isalpha(cur) || cur == '[')
            {
                stk.push(string(1, s[i]));
                i++;
            }
            else // cur == ']'
            {
                vector<string> sub;
                while (stk.top() != "[")
                {
                    sub.push_back(stk.top());
                    stk.pop();
                }
                reverse(sub.begin(), sub.end());
                stk.pop(); // 左括号出栈
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int repeatTime = stoi(stk.top());
                stk.pop();
                string temp = "";
                while (repeatTime--)
                {
                    for (string &str : sub)
                        temp += str;
                }
                stk.push(temp);
                i++;
            }
        }
        string ans = "";
        while (!stk.empty())
        {
            ans.insert(0, stk.top());
            stk.pop();
        }
        return ans;
    }
};
// @lc code=end
