/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start

// 递归快速幂

// class Solution
// {
// public:
//     double myPow(double x, int n)
//     {
//         if (n >= 0)
//             return quickMul(x, (long long)n);
//         else
//             return quickMul(1.0 / x, abs((long long)n));
//     }
//     // 辅函数 - 快速幂
//     double quickMul(double x, long long n)
//     {
//         if (n == 0)
//             return 1.0;
//         double y = quickMul(x, n / 2);
//         if (n % 2 == 0)
//             return y * y;
//         else
//             return y * y * x;
//     }
// };

// 迭代快速幂

class Solution
{
public:
    double myPow(double x, int n)
    {
        unsigned int unsigned_n = abs(n);
        double res = 1.0;
        while (unsigned_n)
        {
            if (unsigned_n & 01)
                res *= x;
            x = x * x;
            unsigned_n >>= 1;
        }
        if (n < 0)
            res = 1.0 / res;
        return res;
    }
};

// @lc code=end
