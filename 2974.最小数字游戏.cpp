/*
 * @lc app=leetcode.cn id=2974 lang=cpp
 *
 * [2974] 最小数字游戏
 */

// @lc code=start
class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        // 特判
        if (nums.empty())
            return {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
            swap(nums[i], nums[i + 1]);
        return nums;
    }
};
// @lc code=end
