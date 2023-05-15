/*
 * @lc app=leetcode.cn id=2239 lang=cpp
 *
 * [2239] 找到最接近 0 的数字
 */

// @lc code=start
class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        int ans = nums[0];
        int minDistanceToZero = abs(nums[0] - 0);
        for (int num : nums)
        {
            int distanceToZero = abs(num - 0);
            if (distanceToZero < minDistanceToZero)
            {
                ans = num;
                minDistanceToZero = distanceToZero;
            }
            if (distanceToZero == minDistanceToZero)
                ans = max(ans, num);
        }
        return ans;
    }
};
// @lc code=end
