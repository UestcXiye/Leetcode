/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1)
            {
                if (nums[mid - 1] == nums[mid])
                    low = mid + 1;
                else
                    high = mid;
            }
            else
            {
                if (nums[mid] == nums[mid + 1])
                    low = mid + 1;
                else
                    high = mid;
            }
        }
        return nums[low];
    }
};
// @lc code=end
