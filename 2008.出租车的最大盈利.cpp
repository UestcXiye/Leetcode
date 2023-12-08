/*
 * @lc app=leetcode.cn id=2008 lang=cpp
 *
 * [2008] 出租车的最大盈利
 */

// @lc code=start

// 排序 + 动态规划 + 二分查找

// class Solution
// {
// private:
//     // 对数组 rides 按 end 从小到大排序
//     static bool cmp(const vector<int> &ride1, const vector<int> &ride2)
//     {
//         return ride1[1] < ride2[1];
//     }

// public:
//     long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
//     {
//         // 特判
//         if (n == 0 || rides.empty())
//             return 0;
//         sort(rides.begin(), rides.end(), cmp);
//         int m = rides.size();
//         // dp[i]: 接区间 [0, i] 内的乘客的最大盈利
//         vector<long long> dp(m + 1, 0);
//         // 初始化
//         dp[0] = 0;
//         // 状态转移
//         for (int i = 1; i <= m; i++)
//         {
//             int j = upper_bound(rides.begin(), rides.begin() + i - 1, rides[i - 1][0], [](int x, const vector<int> &r) -> bool
//                                 { return x < r[1]; }) -
//                     rides.begin();
//             int earning = rides[i - 1][1] - rides[i - 1][0] + rides[i - 1][2];
//             dp[i] = max(dp[i - 1], dp[j] + earning);
//         }
//         return dp[m];
//     }
// };

// 哈希表 + 动态规划

class Solution
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        // 特判
        if (n == 0 || rides.empty())
            return 0;
        unordered_map<int, vector<vector<int>>> rideMap; //<end, {start, tip}>
        for (const vector<int> &ride : rides)
        {
            int start = ride[0], end = ride[1], tip = ride[2];
            rideMap[end].push_back({start, tip});
        }
        // dp[i]: 到达第 i 个地点时能获取的最大盈利
        vector<long long> dp(n + 1, 0);
        // 初始化
        dp[0] = 0;
        // 状态转移
        for (int i = 1; i <= n; i++)
        {
            dp[i] = max(dp[i], dp[i - 1]);
            for (vector<int> &ride : rideMap[i])
            {
                int start = ride[0], end = i, tip = ride[1];
                int earning = end - start + ride[1];
                dp[i] = max(dp[i], dp[start] + earning);
            }
        }
        return dp[n];
    }
};
// @lc code=end
