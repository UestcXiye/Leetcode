/*
 * @lc app=leetcode.cn id=3194 lang=cpp
 *
 * [3194] 最小元素和最大元素的最小平均值
 */

// @lc code=start
class Solution
{
public:
    double minimumAverage(vector<int> &nums)
    {
        int n = nums.size();
        ranges::sort(nums);
        double minAvg = INT_MAX;
        for (int i = 0, j = n - 1; i < j; i++, j--)
            minAvg = min(minAvg, (nums[i] + nums[j]) / 2.0);
        return minAvg;
    }
};
// @lc code=end
