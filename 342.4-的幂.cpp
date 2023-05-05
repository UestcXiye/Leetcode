/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        if (n % 4 == 0)
            return isPowerOfFour(n / 4);
        else
            return false;
    }
};
// @lc code=end
