/*
 * @lc app=leetcode.cn id=1800 lang=cpp
 *
 * [1800] 最大升序子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int i = 0;
        int sum = nums[0], maxSum = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                sum += nums[i];
                maxSum = max(maxSum, sum);
            }
            else
                sum = nums[i];
        }
        return maxSum;
    }
};
// @lc code=end
