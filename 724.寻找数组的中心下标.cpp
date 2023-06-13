/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        int leftSum, rightSum;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                leftSum = 0;
            else
                leftSum = accumulate(nums.begin(), nums.begin() + i, 0);
            if (i == n - 1)
                rightSum = 0;
            else
                rightSum = accumulate(nums.begin() + i + 1, nums.end(), 0);
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }
};
// @lc code=end
