/*
 * @lc app=leetcode.cn id=1523 lang=cpp
 *
 * [1523] 在区间范围内统计奇数数目
 */

// @lc code=start
// class Solution
// {
// public:
//     int countOdds(int low, int high)
//     {
//         int count = 0;
//         for (int i = low; i <= high; i++)
//             if (i % 2)
//                 count++;
//         return count;
//     }
// };
class Solution
{
public:
    int countOdds(int low, int high)
    {
        // 将 [0, high] 中的奇数个数减去 [0, low) 中的奇数个数
        return (high + 1) / 2 - low / 2;
    }
};
// @lc code=end
