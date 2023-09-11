/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start

// 递归

// class Solution
// {
// public:
//     bool isPowerOfFour(int n)
//     {
//         if (n <= 0)
//             return false;
//         if (n == 1)
//             return true;
//         if (n % 4 == 0)
//             return isPowerOfFour(n / 4);
//         else
//             return false;
//     }
// };

// 位运算

// 性质1：如果 n & (n - 1) = 0，那么这个数是 2 的次方。
// 性质2：如果这个数也是 4 的次方，那二进制表示中 1 的位置必须为奇数位。

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        // 把 n 和二进制的 10101...101（即十进制下的1431655765）做按位与，
        // 如果结果不为 0，那么说明这个数是 4 的次方。
        return n > 0 && (n & (n - 1)) == 0 && (n & 1431655765);
    }
};
// @lc code=end
