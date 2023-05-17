/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double quickMul(double x, int n)
    {
        if (n == 0)
            return 1.0;
        double y = quickMul(x, n / 2);
        if (n % 2 == 0)
            return y * y;
        else
            return y * y * x;
    }
    double myPow(double x, int n)
    {
        if (n >= 0)
            return quickMul(x, n);
        else
            return quickMul(1.0 / x, abs(n));
    }
};
// @lc code=end
