/*
 * @lc app=leetcode.cn id=3178 lang=cpp
 *
 * [3178] 找出 K 秒后拿着球的孩子
 */

// @lc code=start
class Solution
{
public:
    int numberOfChild(int n, int k)
    {
        if (k < n)
            return k;
        if ((k / (n - 1)) % 2)
            return n - 1 - k % (n - 1);
        return k % (n - 1);
    }
};
// @lc code=end
