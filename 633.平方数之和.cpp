/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int left = 0, right = sqrt(c);
        while (left <= right)
        {
            if (left * left == c - right * right)
                return true;
            else if (left * left < c - right * right)
                left++;
            else
                right--;
        }
        return false;
    }
};
// @lc code=end
