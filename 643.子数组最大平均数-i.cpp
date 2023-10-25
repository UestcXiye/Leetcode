/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start

// 滑动窗口

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        if (nums.size() == k)
            return (double)accumulate(nums.begin(), nums.end(), 0) / k;
        int window_sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double max_avg = (double)window_sum / k;
        for (int i = k; i < nums.size(); i++)
        {
            window_sum += nums[i];
            window_sum -= nums[i - k];
            max_avg = max(max_avg, (double)window_sum / k);
        }
        return max_avg;
    }
};
// @lc code=end
