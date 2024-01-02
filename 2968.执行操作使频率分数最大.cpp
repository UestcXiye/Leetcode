/*
 * @lc app=leetcode.cn id=2968 lang=cpp
 *
 * [2968] 执行操作使频率分数最大
 */

// @lc code=start

// 贪心 + 前缀和 + 滑动窗口

class Solution
{
public:
    int maxFrequencyScore(vector<int> &nums, long long k)
    {
        // 特判
        if (nums.empty())
            return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            preSum[i] = preSum[i - 1] + nums[i - 1];
        auto calDistance = [&](int left, int i, int right) -> long long
        {
            long long left_distance = (long long)nums[i] * (i - left) - (preSum[i] - preSum[left]);
            long long right_distance = (preSum[right + 1] - preSum[i + 1]) - (long long)nums[i] * (right - i);
            return left_distance + right_distance;
        };
        int ans = 0;
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            while (calDistance(left, (left + right) / 2, right) > k)
                left++;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
