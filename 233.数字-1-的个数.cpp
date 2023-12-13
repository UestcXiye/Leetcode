/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution
{
public:
    int countDigitOne(int n)
    {
        int res = 0;
        long digit = 1;
        int high = n / 10, cur = n % 10, low = 0;
        while (high != 0 || cur != 0)
        {
            if (cur == 0)
                res += high * digit;
            else if (cur == 1)
                res += high * digit + low + 1;
            else
                res += (high + 1) * digit;
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};
// @lc code=end
