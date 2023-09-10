/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start

// Runtime Error
// runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.cpp)

// class Solution
// {
// private:
//     long long factorial(int x)
//     {
//         if (x == 0)
//             return 1;
//         long long product = 1;
//         for (int i = 2; i <= x; i++)
//             product *= i;
//         return product;
//     }

// public:
//     int trailingZeroes(int n)
//     {
//         long long factorialOfn = factorial(n);
//         int count = 0;
//         while (factorialOfn)
//         {
//             if (factorialOfn % 10 == 0)
//                 count++;
//             else
//                 break;
//         }
//         return count;
//     }
// };

class Solution
{
public:
    int trailingZeroes(int n)
    {
        if (n <= 3)
            return 0;
        int countFive = 0, countTwo = 0;
        for (int i = 2; i <= n; i++)
        {
            int num1, num2;
            num1 = num2 = i;
            while (num1 % 2 == 0)
            {
                countTwo++;
                num1 /= 2;
            }
            while (num2 % 5 == 0)
            {
                countFive++;
                num2 /= 5;
            }
        }
        return min(countTwo, countFive);
    }
};
// @lc code=end
