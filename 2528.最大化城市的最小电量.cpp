/*
 * @lc app=leetcode.cn id=2528 lang=cpp
 *
 * [2528] 最大化城市的最小电量
 */

// @lc code=start
class Solution
{
public:
    long long maxPower(vector<int> &stations, int r, int k)
    {
        int n = stations.size();
        vector<long long> preSum(n + 1, 0);
        long long diff[n];
        vector<long long> power(n, 0);

        // 求前缀和
        for (int i = 1; i <= n; i++)
            preSum[i] = preSum[i - 1] + stations[i - 1];
        // 求电量
        for (int i = 0; i < n; ++i)
            power[i] = preSum[min(i + r + 1, n)] - preSum[max(i - r, 0)];

        auto check = [&](long long min_power) -> bool
        {
            memset(diff, 0, sizeof(diff)); // 重置差分数组
            long long sum_d = 0, need = 0;
            for (int i = 0; i < n; i++)
            {
                sum_d += diff[i]; // 累加差分值
                long long m = min_power - power[i] - sum_d;
                if (m > 0)
                { // 需要 m 个供电站
                    need += m;
                    if (need > k)
                        return false; // 提前退出这样快一些
                    sum_d += m;       // 差分更新
                    if (i + r * 2 + 1 < n)
                        diff[i + r * 2 + 1] -= m; // 差分更新
                }
            }
            return true;
        };

        // 二分查找，开区间写法
        long long left = *min_element(power.begin(), power.end());
        long long right = left + k + 1;
        while (left + 1 < right)
        {
            long long mid = left + (right - left) / 2;
            if (check(mid))
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};
// @lc code=end
