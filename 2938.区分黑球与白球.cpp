/*
 * @lc app=leetcode.cn id=2938 lang=cpp
 *
 * [2938] 区分黑球与白球
 */

// @lc code=start
// class Solution
// {
// public:
//     long long minimumSteps(string s)
//     {
//         int white = 0;
//         long long steps = 0;
//         for (int i = 0; i < s.length(); i++)
//         {
//             if (s[i] == '0')
//             {
//                 steps += (long long)(i - white);
//                 white++;
//             }
//         }
//         return steps;
//     }
// };

class Solution
{
public:
    long long minimumSteps(string s)
    {
        int black = 0;
        long long steps = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                steps += black;
            else
                black++;
        }
        return steps;
    }
};
// @lc code=end
