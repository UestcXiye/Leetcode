/*
 * @lc app=leetcode.cn id=2656 lang=cpp
 *
 * [2656] K 个元素的最大和
 */

// @lc code=start
class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int max = nums.back();
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += max + i;
        return sum;
    }
};
// @lc code=end
