/*
 * @lc app=leetcode.cn id=2485 lang=cpp
 *
 * [2485] 找出中枢整数
 */

// @lc code=start
class Solution
{
public:
    int pivotInteger(int n)
    {
        for (int i = n; i > 0; i--)
        {
            int leftSum = 0;
            for (int j = 1; j <= i; j++)
                leftSum += j;
            int rightSum = 0;
            for (int j = i; j <= n; j++)
                rightSum += j;
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }
};
// @lc code=end
