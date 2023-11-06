/*
 * @lc app=leetcode.cn id=1413 lang=cpp
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            preSum[i] = preSum[i - 1] + nums[i - 1];
        return 1 - *min_element(preSum.begin(), preSum.end());
    }
};
// @lc code=end
