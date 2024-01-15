/*
 * @lc app=leetcode.cn id=2957 lang=cpp
 *
 * [2957] 消除相邻近似相等字符
 */

// @lc code=start
// class Solution
// {
// public:
//     int removeAlmostEqualCharacters(string word)
//     {
//         // 特判
//         if (word.empty())
//             return 0;

//         int n = word.length();
//         int i = 1;
//         int ans = 0;
//         while (i < n)
//         {
//             char left = word[i - 1], mid = word[i], right = i + 1 != n ? word[i + 1] : '0';
//             int left_distance = abs(mid - left), right_distance = abs(right - mid);
//             if (left_distance <= 1 && right_distance <= 1)
//             {
//                 // 修改 mid
//                 ans++;
//                 i += 2;
//             }
//             else if (left_distance <= 1)
//             {
//                 // 修改 mid
//                 ans++;
//                 i += 2;
//             }
//             else if (right_distance <= 1)
//             {
//                 // 修改 right
//                 ans++;
//                 i += 3;
//             }
//             else // 无需修改
//                 i++;
//         }
//         return ans;
//     }
// };

// 动态规划

class Solution
{
public:
    int removeAlmostEqualCharacters(string word)
    {
        // 特判
        if (word.size() <= 1)
            return 0;

        int n = word.length();
        // dp[i]: 消除前 i 个字符中所有相邻近似相等字符的最少操作次数
        vector<int> dp(n + 1, 0);

        // 状态转移
        for (int i = 2; i <= n; i++)
        {
            if (abs(word[i - 1] - word[i - 2]) <= 1)
                dp[i] = dp[i - 2] + 1;
            else
                dp[i] = dp[i - 1];
        }
        return dp[n];
    }
};
// @lc code=end
