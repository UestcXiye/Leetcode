/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start

// 模拟栈

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> names = split(path, '/');
        vector<string> stack;
        for (string &name : names)
        {
            if (name == "..")
            {
                if (!stack.empty())
                    stack.pop_back();
            }
            else if (!name.empty() && name != ".")
                stack.push_back(name);
        }
        if (stack.empty())
            return "/";
        string ans;
        for (string &name : stack)
            ans += "/" + name;
        return ans;
    }
    // 辅函数 - 按字符 delim 分割字符串 s
    vector<string> split(const string &s, char delim)
    {
        vector<string> v;
        string cur;
        for (const char &c : s)
        {
            if (c == delim)
            {
                v.push_back(cur);
                cur.clear();
            }
            else
                cur += c;
        }
        v.push_back(cur);
        return v;
    }
};
// @lc code=end
