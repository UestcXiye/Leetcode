/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
// class Solution
// {
// public:
//     int rangeBitwiseAnd(int left, int right)
//     {
//         int shift = 0;
//         // 找到公共前缀
//         while (left < right)
//         {
//             left >>= 1;
//             right >>= 1;
//             shift++;
//         }
//         return left << shift;
//     }
// };

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (left < right)
        {
            // 抹去最右边的 1
            right = right & (right - 1);
        }
        return right;
    }
};

// @lc code=end
