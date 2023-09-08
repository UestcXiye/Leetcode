/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start

// 动态规划

// class Solution
// {
// public:
//     int findLongestChain(vector<vector<int>> &pairs)
//     {
//         // 特判
//         if (pairs.empty())
//             return 0;
//         int n = pairs.size();
//         // 状态数组，并初始化
//         vector<int> dp(n + 1, 1);
//         // dp[i]: 为 pairs[i] 结尾的最长数对链的长度
//         sort(pairs.begin(), pairs.end());
//         //  状态转移
//         for (int i = 1; i <= n; i++)
//             for (int j = 1; j < i; j++)
//                 if (pairs[j - 1][1] < pairs[i - 1][0])
//                     dp[i] = max(dp[i], dp[j] + 1);
//         return dp[n];
//     }
// };

// 贪心 + 二分查找

// class Solution
// {
// public:
//     int findLongestChain(vector<vector<int>> &pairs)
//     {
//         sort(pairs.begin(), pairs.end());
//         vector<int> dp;
//         for (auto &pair : pairs)
//         {
//             int x = pair[0], y = pair[1];
//             if (dp.empty() || dp.back() < x)
//                 dp.push_back(y);
//             else
//             {
//                 auto iter = lower_bound(dp.begin(), dp.end(), x);
//                 *iter = min(*iter, y);
//             }
//         }
//         return dp.size();
//     }
// };

// 贪心

class Solution
{
private:
    // 排序函数
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }

public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int cur = INT_MIN, res = 0;
        sort(pairs.begin(), pairs.end(), cmp);
        for (auto &pair : pairs)
        {
            int x = pair[0], y = pair[1];
            if (cur < x)
            {
                cur = y;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
