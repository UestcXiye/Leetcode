/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// 性质1：已知 rand_N() 可以等概率的生成 [1, N] 范围的随机数，
// 那么(rand_X() - 1) × Y + rand_Y()可以等概率的生成 [1, X * Y] 范围的随机数，
// 即实现了 rand_XY()。

// 性质2：已知 rand_N() 可以等概率的生成 [1, N] 范围的随机数，
//  若 N % X = 0，则 rand_N() % X + 1 可以等概率的生成 [1, X] 范围的随机数，
// 即实现了 rand_X()。

// 拒绝采样：如果某个采样结果不在要求的范围内，则丢弃它。

// 要实现 rand10()，就需要先实现 rand_N()，并且保证 N >= 10 且 N % 10 = 0。
// 这样再通过 rand_N() % 10 + 1 就可以得到 [1,10] 范围的随机数了。

// class Solution
// {
// public:
//     int rand10()
//     {
//         while (true)
//         {
//             // 等概率生成 [1,49] 范围的随机数
//             int num = (rand7() - 1) * 7 + rand7();
//             if (num <= 40)
//                 return num % 10 + 1; // 拒绝采样，并返回 [1,10] 范围的随机数
//         }
//     }
// };

// 优化

class Solution
{
public:
    int rand10()
    {
        while (true)
        {
            int a = rand7();
            int b = rand7();
            int num = (a - 1) * 7 + b; // rand 49
            if (num <= 40)
                return num % 10 + 1; // 拒绝采样
            // num 的范围为 [41, 49]
            a = num - 40; // rand 9
            b = rand7();
            num = (a - 1) * 7 + b; // rand 63
            if (num <= 60)
                return num % 10 + 1;
            // num 的范围为 [61, 63]
            a = num - 60; // rand 3
            b = rand7();
            num = (a - 1) * 7 + b; // rand 21
            if (num <= 20)
                return num % 10 + 1;
        }
    }
};
// @lc code=end
