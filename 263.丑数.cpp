/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;

        if (n % 5 == 0)
            return isUgly(n / 5);
        if (n % 3 == 0)
            return isUgly(n / 3);
        if (n % 2 == 0)
            return isUgly(n / 2);

        return n == 1;
    }
};
// @lc code=end
