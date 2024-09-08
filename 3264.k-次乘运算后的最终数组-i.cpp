/*
 * @lc app=leetcode.cn id=3264 lang=cpp
 *
 * [3264] K 次乘运算后的最终数组 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        int n = nums.size();
        while (k--)
        {
            int min_idx = 0;
            for (int i = 1; i < n; i++)
                if (nums[i] < nums[min_idx])
                    min_idx = i;
            nums[min_idx] *= multiplier;
        }
        return nums;
    }
};
// @lc code=end
