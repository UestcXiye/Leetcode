/*
 * @lc app=leetcode.cn id=3021 lang=cpp
 *
 * [3021] Alice 和 Bob 玩鲜花游戏
 */

// @lc code=start

// Time Limit Exceeded

// class Solution
// {
// public:
//     long long flowerGame(int n, int m)
//     {
//         long long count = 0;
//         for (int x = 1; x <= n; x++)
//             for (int y = 1; y <= m; y++)
//                 if ((x + y) ^ 0x1)
//                     count++;
//         return count / 2;
//     }
// };

// class Solution
// {
// public:
//     long long flowerGame(int n, int m)
//     {
//         return (long long)(n / 2) * ((m + 1) / 2) +
//                (long long)((n + 1) / 2) * (m / 2);
//     }
// };

// 数学

class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        return (long long)n * m / 2;
    }
};
// @lc code=end
