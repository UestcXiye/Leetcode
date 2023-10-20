/*
 * @lc app=leetcode.cn id=2875 lang=cpp
 *
 * [2875] 无限数组的最短子数组
 */

// @lc code=start

// 滑动窗口

class Solution
{
public:
    int minSizeSubarray(vector<int> &nums, int target)
    {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        for (int i = 0; i < n - 1; i++)
            nums.push_back(nums[i]);
        long long sum = 0;
        int left = 0, len = INT_MAX;
        for (int right = 0; right < 2 * n - 1; right++)
        {
            sum += nums[right];
            while (sum > target % total)
            {
                sum -= nums[left];
                left++;
            }
            int cur_len = right - left + 1;
            if (sum == target % total)
                len = min(len, cur_len);
        }
        return len == INT_MAX ? -1 : len + target / total * n;
    }
};
// @lc code=end
