/*
 * @lc app=leetcode.cn id=2086 lang=cpp
 *
 * [2086] 从房屋收集雨水需要的最少水桶数
 */

// @lc code=start

// 贪心

// class Solution
// {
// public:
//     int minimumBuckets(string hamsters)
//     {
//         int n = hamsters.size();
//         int bucket = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (hamsters[i] == 'H')
//             {
//                 if (i + 1 < n && hamsters[i + 1] == '.')
//                 {
//                     bucket++;
//                     i += 2;
//                 }
//                 else if (i - 1 >= 0 && hamsters[i - 1] == '.')
//                     bucket++;
//                 else
//                     return -1;
//             }
//         }
//         return bucket;
//     }
// };

class Solution
{
private:
#define INF 0x3F3F3F3F
#define MAX_LEN 1e5 + 10

public:
    int minimumBuckets(string street)
    {
        int n = street.size();
        vector<int> dp(MAX_LEN, INF);
        // 初始化
        dp[0] = 0;
        // 状态转移
        for (int i = 1; i <= n; i++)
        {
            if (street[i - 1] == '.')
            {
                dp[i] = dp[i - 1];
                if (i - 2 >= 0 && street[i - 2] == 'H')
                    dp[i] = min(dp[i], dp[i - 2] + 1);
            }
            else if (street[i - 1] == 'H')
            {
                if (i - 2 >= 0 && street[i - 2] == '.')
                {
                    dp[i] = dp[i - 2] + 1;
                    if (i - 3 >= 0 && street[i - 3] == 'H')
                    {
                        dp[i] = min(dp[i], dp[i - 3] + 1);
                    }
                }
            }
        }
        return dp[n] >= INF ? -1 : dp[n];
    }
};
// @lc code=end
