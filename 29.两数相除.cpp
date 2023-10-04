/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start

// 递归

class Solution
{
public:
    // 要求不使用 乘法、除法和取余运算
    int divide(int dividend, int divisor)
    {
        // 考虑被除数为最小值的情况
        if (dividend == INT_MIN)
        {
            if (divisor == 1)
                return INT_MIN;
            if (divisor == -1)
                return INT_MAX;
        }
        // 考虑除数为最小值的情况
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        // 考虑被除数为 0 的情况
        if (dividend == 0)
            return 0;
        // 一般情况
        if (dividend > 0)
            return -divide(-dividend, divisor);
        if (divisor > 0)
            return -divide(dividend, -divisor);
        if (dividend > divisor)
            return 0;
        int res = 1, tmp = divisor;
        while ((dividend - divisor) <= divisor)
        {
            res += res;
            divisor += divisor;
        }
        return res + divide(dividend - divisor, tmp);
    }
};
// @lc code=end
