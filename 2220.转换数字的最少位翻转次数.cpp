/*
 * @lc app=leetcode.cn id=2220 lang=cpp
 *
 * [2220] 转换数字的最少位翻转次数
 */

// @lc code=start
// class Solution
// {
// public:
//     string turnToBits(int num)
//     {
//         string bits;
//         while (num)
//         {
//             bits += to_string(num % 2);
//             num /= 2;
//         }
//         return bits;
//     }
//     int minBitFlips(int start, int goal)
//     {
//         int ans = 0;
//         string startBits = turnToBits(start);
//         string goalBits = turnToBits(goal);
//         if (startBits.size() < goalBits.size())
//             startBits.append(goalBits.size() - startBits.size(), '0');
//         else
//             goalBits.append(startBits.size() - goalBits.size(), '0');
//         for (int i = 0; i < startBits.size(); i++)
//             if (startBits[i] != goalBits[i])
//                 ans++;
//         return ans;
//     }
// };
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int temp = start ^ goal;
        int ans = 0;
        while (temp)
        {
            ans += temp & 1;
            temp >>= 1;
        }
        return ans;
    }
};
// @lc code=end
