/*
 * @lc app=leetcode.cn id=2855 lang=cpp
 *
 * [2855] 使数组成为递增数组的最少右移次数
 */

// @lc code=start
class Solution
{
public:
    int minimumRightShifts(vector<int> &nums)
    {
        int n = nums.size(), k = -1;
        for (int i = 1; i <= n; i++)
        {
            if (nums[i % n] < nums[i - 1])
            {
                if (k == -1)
                    k = i;
                else
                    return -1;
            }
        }
        return k == -1 ? 0 : n - k;
    }
};
// @lc code=end
