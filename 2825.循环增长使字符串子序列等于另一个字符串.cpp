/*
 * @lc app=leetcode.cn id=2825 lang=cpp
 *
 * [2825] 循环增长使字符串子序列等于另一个字符串
 */

// @lc code=start

// 双指针

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        // 特判
        if (str1.length() < str2.length())
            return false;
        if (str1 == str2)
            return true;

        int len1 = str1.length(), len2 = str2.length();
        int i = 0, j = 0;
        for (int i = 0; i < len1; i++)
        {
            if (match(str1[i], str2[j]))
                j++;
            if (j == len2)
                return true;
        }
        return false;
    }
    // 辅函数 - 判断字符 c1 和 c2 是否匹配
    bool match(char c1, char c2)
    {
        if (c1 == c2)
            return true;
        c1 = c1 == 'z' ? 'a' : char(c1 + 1);
        return c1 == c2;
        // return (c2 - c1 + 26) % 26 <= 1;
    }
};
// @lc code=end
