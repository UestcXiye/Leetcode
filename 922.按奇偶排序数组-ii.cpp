/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int n = nums.size(), odd = 1;
        for (int even = 0; even < n; even += 2)
        {
            if (nums[even] % 2 == 1)
            {
                while (odd < n && nums[odd] % 2 == 1)
                    odd += 2;
                swap(nums[even], nums[odd]);
            }
        }
        return nums;
    }
};
// @lc code=end
