/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */

// @lc code=start
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        int len1 = str1.size(), len2 = str2.size();
        for (int i = min(len1, len2); i >= 1; i--)
        {
            if (len1 % i == 0 && len2 % i == 0)
            {
                string x = str1.substr(0, i);
                if (check(str1, x) && check(str2, x))
                    return x;
            }
        }
        return "";
    }
    // 辅函数 - 判断 x 能否除尽 s
    bool check(string &s, string &x)
    {
        string str = "";
        for (int i = 0; i < s.size() / x.size(); i++)
            str += x;
        return s == str;
    }
};
// @lc code=end
