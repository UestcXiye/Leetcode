/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int repeat = 0;
        for (int i = 1; i < n; i++)
            if (nums[i] == nums[i - 1])
                repeat = nums[i];
        return {repeat, n * (n + 1) / 2 - accumulate(nums.begin(), nums.end(), 0) + repeat};
    }
};
// @lc code=end
