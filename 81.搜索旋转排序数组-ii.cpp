/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[left] == nums[mid])
            {
                // 无法判断哪个区间是增序的
                left++;
            }
            else if (nums[right] == nums[mid])
            {
                // 无法判断哪个区间是增序的
                right--;
            }
            else if (nums[mid] < nums[right])
            {
                // 右区间是增序的
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                // 左区间是增序的
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end
