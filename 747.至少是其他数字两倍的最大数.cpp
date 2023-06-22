/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int n = nums.size();
        int maxNum = nums[0], maxIndex = 0;
        for (int i = 1; i < n; i++)
            if (maxNum < nums[i])
            {
                maxNum = nums[i];
                maxIndex = i;
            }
        sort(nums.begin(), nums.end());
        return maxNum >= 2 * nums[n - 2] ? maxIndex : -1;
    }
};
// @lc code=end
