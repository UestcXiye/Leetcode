/*
 * @lc app=leetcode.cn id=2784 lang=cpp
 *
 * [2784] 检查数组是否是好的
 */

// @lc code=start
class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() - 1 != nums.back())
            return false;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] != i + 1)
                return false;
        return true;
    }
};
// @lc code=end
