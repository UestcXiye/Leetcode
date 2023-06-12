/*
 * @lc app=leetcode.cn id=6470 lang=cpp
 *
 * [6470] 既不是最小值也不是最大值
 */

// @lc code=start
class Solution
{
public:
    int findNonMinOrMax(vector<int> &nums)
    {
        int ans = -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minNum = nums[0], maxNum = nums[n - 1];
        for (int &number : nums)
            if (number != minNum && number != maxNum)
            {
                ans = number;
                break;
            }
        return ans;
    }
};
// @lc code=end
