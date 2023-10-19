/*
 * @lc app=leetcode.cn id=2894 lang=cpp
 *
 * [2894] 分类求和并作差
 */

// @lc code=start
// class Solution
// {
// public:
//     int differenceOfSums(int n, int m)
//     {
//         int num1 = 0, num2 = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             if (i % m == 0)
//                 num2 += i;
//             else
//                 num1 += i;
//         }
//         return num1 - num2;
//     }
// };

class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        // total = num1 + num2
        // ans = num1 - num2 = total - 2 * num2
        int num = 0;
        for (int i = 1; i <= n; i++)
            if (i % m == 0)
                num += i;
        return (1 + n) * n / 2 - 2 * num;
    }
};
// @lc code=end
