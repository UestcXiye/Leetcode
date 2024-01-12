/*
 * @lc app=leetcode.cn id=2645 lang=cpp
 *
 * [2645] 构造有效字符串的最少插入数
 */

// @lc code=start

// 枚举 + 数学

// class Solution
// {
// public:
//     int addMinimum(string word)
//     {
//         // 标记前一个字符，初始为 c
//         char last = 'c';
//         // 插入的字符数
//         int add = 0;
//         for (char &cur : word)
//         {
//             // 插入的字符数，为当前字符与前一个字符的差距值 -1
//             add += (cur - last - 1 + 3) % 3;
//             last = cur;
//         }
//         // 最后还要校验最后一个字符之后是否需要插入字符
//         add += ('a' - last - 1 + 3) % 3;
//         return add;
//     }
// };

// 动态规划

class Solution
{
public:
    int addMinimum(string word)
    {
        int n = word.length();
        vector<int> dp(n + 1, 0);
        // 初始化
        dp[0] = 0;
        // 状态转移
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + 2;
            if (i > 1 && word[i - 1] > word[i - 2])
                dp[i] = dp[i - 1] - 1;
        }
        return dp[n];
    }
};

// @lc code=end
