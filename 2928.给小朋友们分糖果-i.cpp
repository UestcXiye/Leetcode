/*
 * @lc app=leetcode.cn id=2928 lang=cpp
 *
 * [2928] 给小朋友们分糖果 I
 */

// @lc code=start

// 暴力

// class Solution
// {
// public:
//     int distributeCandies(int n, int limit)
//     {
//         if (n > 3 * limit)
//             return 0;
//         int count = 0;
//         for (int i = 0; i <= limit; i++)
//             for (int j = 0; j <= limit; j++)
//                 for (int k = 0; k <= limit; k++)
//                     if (i + j + k == n)
//                         count++;
//         return count;
//     }
// };

// 一次遍历

class Solution
{
public:
    int distributeCandies(int n, int limit)
    {
        if (n > 3 * limit)
            return 0;
        int count = 0;
        for (int i = max(0, n - 2 * limit); i <= min(n, limit); i++)
        {
            int remain = n - i;
            int maxCandies = min(remain, limit);
            int minCandies = max(0, remain - limit);
            count += maxCandies - minCandies + 1;
        }
        return count;
    }
};

// 容斥原理

// class Solution
// {
//     int c2(int n)
//     {
//         return n > 1 ? n * (n - 1) / 2 : 0;
//     }

// public:
//     int distributeCandies(int n, int limit)
//     {
//         return c2(n + 2) - 3 * c2(n - limit + 1) + 3 * c2(n - 2 * limit) - c2(n - 3 * limit - 1);
//     }
// };
// @lc code=end
