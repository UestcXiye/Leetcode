/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */

// @lc code=start
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int max_frq = 1;
        long long sum = 0;
        // 枚举窗口的右边界
        for (int right = 1; right < n; right++)
        {
            long long addition = 1LL * (nums[right] - nums[right - 1]) * (right - left);
            sum += addition;
            // 修改窗口的左边界
            while (sum > k)
            {
                int diff = nums[right] - nums[left];
                sum -= diff;
                left++;
            }
            int cur_frq = right - left + 1;
            max_frq = max(max_frq, cur_frq);
        }
        return max_frq;
    }
};
// @lc code=end
