/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 *
 * [1410] HTML 实体解析器
 */

// @lc code=start
class Solution
{
public:
    string entityParser(string text)
    {
        string result;
        int i = 0;
        while (i < text.size())
        {
            if (text[i] == '&')
            {
                if (text.substr(i, 4) == "&gt;")
                {
                    result += '>';
                    i += 4;
                }
                else if (text.substr(i, 4) == "&lt;")
                {
                    result += '<';
                    i += 4;
                }
                else if (text.substr(i, 5) == "&amp;")
                {
                    result += '&';
                    i += 5;
                }
                else if (text.substr(i, 6) == "&quot;")
                {
                    result += '"';
                    i += 6;
                }
                else if (text.substr(i, 6) == "&apos;")
                {
                    result += '\'';
                    i += 6;
                }
                else if (text.substr(i, 7) == "&frasl;")
                {
                    result += '/';
                    i += 7;
                }
                else
                    result += text[i++];
            }
            else
                result += text[i++];
        }
        return result;
    }
};
// @lc code=end
