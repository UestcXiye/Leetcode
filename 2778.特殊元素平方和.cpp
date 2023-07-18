/*
 * @lc app=leetcode.cn id=2778 lang=cpp
 *
 * [2778] 特殊元素平方和
 */

// @lc code=start
class Solution
{
public:
    int sumOfSquares(vector<int> &nums)
    {
        int n = nums.size();
        int sumOfSquares = 0;
        for (int i = 0; i < n; i++)
            if (n % (i + 1) == 0)
                sumOfSquares += nums[i] * nums[i];
        return sumOfSquares;
    }
};
// @lc code=end
