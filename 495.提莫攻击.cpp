/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
// class Solution
// {
// public:
//     int findPoisonedDuration(vector<int> &timeSeries, int duration)
//     {
//         int sum = 0;
//         int expired = 0; // 中毒结束时间
//         int n = timeSeries.size();
//         for (int i = 0; i < n; i++)
//         {
//             if (timeSeries[i] >= expired)
//                 sum += duration;
//             else
//                 sum += timeSeries[i] - expired + duration;
//             expired = timeSeries[i] + duration;
//         }
//         return sum;
//     }
// };

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int n = timeSeries.size();
        int sum = timeSeries[n - 1] + duration - 1;
        for (int i = n - 1; i > 0; i--)
        {
            if (timeSeries[i] - timeSeries[i - 1] > duration)
                sum -= timeSeries[i] - timeSeries[i - 1] - duration;
        }
        sum -= (timeSeries[0] - 1);
        return sum;
    }
};
// @lc code=end
