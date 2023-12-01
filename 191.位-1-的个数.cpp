/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        unsigned int flag = 1;
        while (flag)
        {
            if (n & flag)
                count++;
            flag <<= 1;
        }
        return count;
    }
};

// class Solution
// {
// public:
//     int hammingWeight(uint32_t n)
//     {
//         int count = 0;
//         while (n)
//         {
//             n &= (n - 1);
//             count++;
//         }
//         return count;
//     }
// };
// @lc code=end
