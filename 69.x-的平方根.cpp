/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        int left = 1, right = x;
        while (left <= right)
        {
            // int mid = (left + right) / 2;
            int mid = left + (right - left) / 2;
            if (x / mid == mid)
                return mid;
            else if (x / mid < mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};
// class Solution
// {
// public:
//     int mySqrt(int a)
//     {
//         long x = a;
//         while (x * x > a)
//         {
//             x = (x + a / x) / 2;
//         }
//         return x;
//     }
// };
// @lc code=end
