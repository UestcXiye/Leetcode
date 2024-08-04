/*
 * @lc app=leetcode.cn id=3226 lang=cpp
 *
 * [3226] 使两个整数相等的位更改次数
 */

// @lc code=start
class Solution
{
public:
    int minChanges(int n, int k)
    {
        return (n & k) != k ? -1 : __builtin_popcount(n ^ k);
    }
};
// @lc code=end
