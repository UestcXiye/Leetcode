/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 *
 * [2582] 递枕头
 */

// @lc code=start
class Solution
{
public:
    int passThePillow(int n, int time)
    {
        // 走一趟需要n-1秒
        if ((time / (n - 1)) % 2) // 走了奇数趟
            return n - time % (n - 1);
        else // 走了偶数趟
            return 1 + time % (n - 1);
    }
};
// @lc code=end
