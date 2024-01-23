/*
 * @lc app=leetcode.cn id=3014 lang=cpp
 *
 * [3014] 输入单词需要的最少按键次数 I
 */

// @lc code=start
// class Solution
// {
// public:
//     int minimumPushes(string word)
//     {
//         // 特判
//         if (word.empty())
//             return 0;

//         const string special = "1*#0";
//         int count_sp = 0, count_alpha = 0;
//         for (char &c : word)
//         {
//             if (special.find(c) != string::npos)
//                 count_sp++;
//             else
//                 count_alpha++;
//         }
//         int ans = 0, x = 1;
//         while (count_alpha >= 8)
//         {

//             ans += 8 * x;
//             x++;
//             count_alpha -= 8;
//         }
//         ans += count_alpha * x + count_sp;
//         return ans;
//     }
// };

// 数学

class Solution
{
public:
    int minimumPushes(string word)
    {
        // 特判
        if (word.empty())
            return 0;

        int n = word.length();
        int k = n / 8;
        return (k * 4 + n % 8) * (k + 1);
    }
};

// @lc code=end
