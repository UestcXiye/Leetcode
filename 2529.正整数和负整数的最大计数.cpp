/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lc code=start
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int countPos = 0, countNeg = 0;
        for (int num : nums)
        {
            if (num > 0)
                countPos++;
            if (num < 0)
                countNeg++;
        }
        return max(countPos, countNeg);
    }
};
// @lc code=end
