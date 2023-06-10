/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());
        if (nums.size() < 2)
            return;
        // all in [0, zero) = 0
        // all in [zero, i) = 1
        // all in [two, nums.size() - 1] = 2
        int zero = 0, two = nums.size();
        int i = 0;
        while (i < two)
        {
            if (nums[i] == 0)
            {
                swap(nums[zero], nums[i]);
                zero++;
                i++;
            }
            else if (nums[i] == 1)
                i++;
            else
            {
                two--;
                swap(nums[i], nums[two]);
            }
        }
    }
};
// @lc code=end
