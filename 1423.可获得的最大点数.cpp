/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start

// 前缀和 + 后缀和

// class Solution
// {
// public:
//     int maxScore(vector<int> &cardPoints, int k)
//     {
//         if (k == 0)
//             return 0;
//         if (k == cardPoints.size())
//             return accumulate(cardPoints.begin(), cardPoints.end(), 0);
//         int n = cardPoints.size();
//         vector<int> prevSum(n + 1, 0), suffixSum(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//             prevSum[i] = prevSum[i - 1] + cardPoints[i - 1];
//         for (int i = n - 1; i >= 0; i--)
//             suffixSum[i] = suffixSum[i + 1] + cardPoints[i];
//         // reverse(suffixSum.begin(), suffixSum.end());
//         int max_sum = 0;
//         for (int i = 0; i <= k; i++)
//         {
//             max_sum = max(max_sum, prevSum[i] + suffixSum[n - (k - i)]);
//         }
//         return max_sum;
//     }
// };

// 滑动窗口

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        if (k == 0)
            return 0;
        if (k == cardPoints.size())
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int n = cardPoints.size();
        int windowSize = n - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0), min_sum = sum;
        for (int i = windowSize; i < n; i++)
        {
            sum += cardPoints[i];
            sum -= cardPoints[i - windowSize];
            min_sum = min(min_sum, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - min_sum;
    }
};
// @lc code=end
