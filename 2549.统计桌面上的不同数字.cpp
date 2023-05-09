/*
 * @lc app=leetcode.cn id=2549 lang=cpp
 *
 * [2549] 统计桌面上的不同数字
 */

// @lc code=start
class Solution
{
public:
    int distinctIntegers(int n)
    {
        if (n == 1)
            return 1;
        return n - 1;
    }
};
// @lc code=end
