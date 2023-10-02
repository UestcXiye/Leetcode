/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start

// 模拟

class Solution
{
public:
    int myAtoi(string s)
    {
        // 特判
        if (s.empty())
            return 0;
        int i = 0, n = s.size(), sign = 1, num = 0;
        // 处理前置空格
        while (i < n && s[i] == ' ')
            i++;
        // 处理并记录符号位
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }
        // 处理数字
        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';
            // 判断是否溢出
            if (num > (INT_MAX - digit) / 10) // 等效于 10*num+digit>INT_MAX
                return sign == 1 ? INT_MAX : INT_MIN;
            num = 10 * num + digit;
            i++;
        }
        return sign * num;
    }
};
// @lc code=end
