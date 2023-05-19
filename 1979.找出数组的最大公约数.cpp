/*
 * @lc app=leetcode.cn id=1979 lang=cpp
 *
 * [1979] 找出数组的最大公约数
 */

// @lc code=start
class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max = nums[n - 1], min = nums[0];
        for (int i = min; i >= 1; i--)
            if (max % i == 0 && min % i == 0)
                return i;
        return 1;
    }
};
// @lc code=end
