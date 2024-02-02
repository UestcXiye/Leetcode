/*
 * @lc app=leetcode.cn id=3012 lang=cpp
 *
 * [3012] 通过操作使数组长度最小
 */

// @lc code=start
class Solution
{
public:
    int minimumArrayLength(vector<int> &nums)
    {
        int min_x = *min_element(nums.begin(), nums.end());
        for (int &num : nums)
        {
            if (num % min_x)
                return 1;
        }
        return (ranges::count(nums, min_x) + 1) / 2;
    }
};
// @lc code=end
