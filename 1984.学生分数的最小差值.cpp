/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minDiff = __INT_MAX__;
        for (int i = 0; i <= n - k; i++)
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        return minDiff;
    }
};
// @lc code=end
