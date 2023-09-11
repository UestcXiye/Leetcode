/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start

// 模拟

// class Solution
// {
// private:
//     void reverseBit(int &bit)
//     {
//         if (bit)
//             bit = 0;
//         else
//             bit = 1;
//     }

// public:
//     bool hasAlternatingBits(int n)
//     {
//         int bit = n & 01;
//         // bit = ~bit 是错的
//         reverseBit(bit);
//         while (n)
//         {
//             if (!((n & 01) ^ bit))
//                 return false;
//             reverseBit(bit);
//             n >>= 1;
//         }
//         return true;
//     }
// };

// 位运算

// 性质1：当且仅当 n 为交替位二进制数时，n ^ (n >> 1) 的二进制表示全为 1。
// 性质2：当且仅当 a 的二进制表示全为 1 时，(a & (a + 1)) = 0。

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};
// @lc code=end
