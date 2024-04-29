/*
 * @lc app=leetcode.cn id=3133 lang=cpp
 *
 * [3133] 数组最后一个元素的最小值
 */

// @lc code=start

// 位运算

// class Solution
// {
// public:
//     long long minEnd(int n, int x)
//     {
//         n--; // 先把 n 减一，这样下面讨论的 n 就是原来的 n-1
//         long long ans = x;
//         // n 的第 j 个比特（从右往左）填到 x 的第 i 个比特上
//         int i = 0, j = 0;
//         while (n >> j)
//         {
//             // x 的第 i 个比特值是 0，即「空位」
//             if (((ans >> i) & 01) == 0)
//             {
//                 // 空位填入 n 的第 j 个比特值
//                 int bit = (n >> j) & 01;
//                 ans |= (long long)bit << i;
//                 j++;
//             }
//             i++;
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        n--;
        long long ans = x;
        int j = 0;
        for (long long t = ~x, lb; n >> j; t ^= lb)
        {
            lb = t & -t;
            int bit = (n >> j) & 1;
            ans |= (long long)bit * lb;
            j++;
        }
        return ans;
    }
};
// @lc code=end
