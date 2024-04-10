/*
 * @lc app=leetcode.cn id=3107 lang=cpp
 *
 * [3107] 使数组中位数等于 K 的最少操作数
 */

// @lc code=start
class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n / 2];
        // if (n % 2)
        //     median = nums[n / 2];
        // else
        //     median = max(nums[n / 2 - 1], nums[n / 2]);
        long long op = 0;
        op += abs(median - k);
        int i = n / 2 - 1;
        while (i >= 0 && nums[i] > k)
        {
            op += nums[i] - k;
            i--;
        }
        i = n / 2 + 1;
        while (i < n && nums[i] < k)
        {
            op += k - nums[i];
            i++;
        }
        return op;
    }
};
// @lc code=end
