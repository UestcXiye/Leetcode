/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (nums[right] % 2 == 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
            else
                right--;
        }
        return nums;
    }
};
// @lc code=end
