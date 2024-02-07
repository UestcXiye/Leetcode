/*
 * @lc app=leetcode.cn id=3024 lang=cpp
 *
 * [3024] 三角形类型 II
 */

// @lc code=start
class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[1], c = nums[2];
        if (a + b <= c)
            return "none";
        if (a == b && b == c)
            return "equilateral";
        else if (a == b || b == c)
            return "isosceles";
        return "scalene";
    }
};
// @lc code=end
