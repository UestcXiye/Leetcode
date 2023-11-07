/*
 * @lc app=leetcode.cn id=2909 lang=cpp
 *
 * [2909] 元素和最小的山形三元组 II
 */

// @lc code=start
class Solution
{
public:
    int minimumSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> preMin(n);
        preMin[0] = nums[0];
        for (int i = 1; i < n; i++)
            preMin[i] = min(preMin[i - 1], nums[i]);
        vector<int> sufMin(n);
        sufMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            sufMin[i] = min(sufMin[i + 1], nums[i]);
        int minimumSum = INT_MAX;
        for (int j = 1; j < n - 1; j++)
            if (preMin[j - 1] < nums[j] && nums[j] > sufMin[j + 1])
                minimumSum = min(minimumSum, preMin[j - 1] + nums[j] + sufMin[j + 1]);
        return minimumSum == INT_MAX ? -1 : minimumSum;
    }
};
// @lc code=end
