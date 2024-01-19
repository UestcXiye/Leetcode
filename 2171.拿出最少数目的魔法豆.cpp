/*
 * @lc app=leetcode.cn id=2171 lang=cpp
 *
 * [2171] 拿出最少数目的魔法豆
 */

// @lc code=start

// 数学

// class Solution
// {
// public:
//     long long minimumRemoval(vector<int> &beans)
//     {
//         int n = beans.size();
//         long long total = 0;
//         sort(beans.begin(), beans.end());
//         long long max_area = 0;
//         // 枚举保留的魔法豆的数目
//         for (int i = 0; i < n; i++)
//         {
//             total += beans[i];
//             // 相当于在一个单调曲线下取一个最大矩形
//             max_area = max(max_area, (long long)(n - i) * beans[i]);
//         }
//         return total - max_area;
//     }
// };

// 排序 + 前缀和

class Solution
{
public:
    long long minimumRemoval(vector<int> &beans)
    {
        int n = beans.size();
        sort(beans.begin(), beans.end());

        vector<long long> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            preSum[i] = preSum[i - 1] + beans[i - 1];

        long long minDelete = LONG_LONG_MAX;
        for (int i = 0; i < n; i++)
        {
            // 左边要删除的魔法豆个数
            long long leftSum = preSum[i];
            // 右边要删除的魔法豆个数
            long long rightDelete = (preSum[n] - preSum[i]) - (long long)(n - i) * beans[i];
            minDelete = min(minDelete, leftSum + rightDelete);
        }
        return minDelete;
    }
};
// @lc code=end
