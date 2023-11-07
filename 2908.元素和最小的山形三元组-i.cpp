/*
 * @lc app=leetcode.cn id=2908 lang=cpp
 *
 * [2908] 元素和最小的山形三元组 I
 */

// @lc code=start
class Solution
{
public:
    int minimumSum(vector<int> &nums)
    {
        int n = nums.size();
        int sum = INT_MAX;
        for (int i = 0; i < n - 2; i++)
            for (int j = i + 1; j < n - 1; j++)
                for (int k = j + 1; k < n; k++)
                    if (nums[i] < nums[j] && nums[j] > nums[k])
                        sum = min(sum, nums[i] + nums[j] + nums[k]);
        return sum == INT_MAX ? -1 : sum;
    }
};
// @lc code=end
