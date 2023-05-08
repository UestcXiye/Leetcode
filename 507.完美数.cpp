/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
// class Solution
// {
// public:
//     bool checkPerfectNumber(int num)
//     {
//         int sum = 0;
//         for (int i = 1; i < num; i++)
//             if (num % i == 0)
//                 sum += i;
//         return sum == num;
//     }
// };

class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;
        int sum = 0;
        for (int i = 1; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                sum += i;
                if (i * i < num && i != 1)
                    sum += num / i;
            }
        }
        return sum == num;
    }
};

// class Solution
// {
// public:
//     bool checkPerfectNumber(int num)
//     {
//         return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;
//     }
// };

// @lc code=end
