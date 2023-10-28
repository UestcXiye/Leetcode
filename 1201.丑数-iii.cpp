/*
 * @lc app=leetcode.cn id=1201 lang=cpp
 *
 * [1201] 丑数 III
 */

// @lc code=start

// 容斥定理 + 二分查找

class Solution
{
private:
    long gcd(long x, long y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    long lcm(long x, long y)
    {
        return x / gcd(x, y) * y;
    }

public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        long left = 0, right = 2 * 10e9;
        while (left < right)
        {
            auto check = [&](int mid, int n, int a, int b, int c) -> bool
            {
                long ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c), abc = lcm(lcm(a, b), c);
                long cnt = (long)mid / a + mid / b + mid / c - mid / ac - mid / bc - mid / ab + mid / abc;
                return cnt >= n;
            };

            int mid = left + (right - left) / 2;
            if (check(mid, n, a, b, c))
                right = mid;
            else
                left = mid + 1;
        }
        return (int)left;
    }
};
// @lc code=end
