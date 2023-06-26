/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */

// @lc code=start
class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = n - 1; i >= 2; i--)
            if (nums[i - 2] + nums[i - 1] > nums[i])
                return nums[i - 2] + nums[i - 1] + nums[i];
        return 0;
    }
};
// @lc code=end
