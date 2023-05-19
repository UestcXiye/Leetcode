/*
 * @lc app=leetcode.cn id=1991 lang=cpp
 *
 * [1991] 找到数组的中间位置
 */

// @lc code=start
class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        int n = nums.size();
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), -nums[0]);
        for (int i = 0; i < n - 1; i++)
        {
            if (leftSum == rightSum)
                return i;
            else
            {
                leftSum += nums[i];
                rightSum -= nums[i + 1];
            }
        }
        return accumulate(nums.begin(), nums.end() - 1, 0) == 0 ? n - 1 : -1;
    }
};
// @lc code=end
