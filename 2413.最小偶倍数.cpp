/*
 * @lc app=leetcode.cn id=2413 lang=cpp
 *
 * [2413] 最小偶倍数
 */

// @lc code=start
class Solution
{
public:
    int smallestEvenMultiple(int n)
    {
        if (n == 1)
            return 2;
        if (n % 2)
            return 2 * n;
        return n;
    }
};
// @lc code=end
