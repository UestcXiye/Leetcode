/*
 * @lc app=leetcode.cn id=10036 lang=cpp
 *
 * [10036] 捕获黑皇后需要的最少移动次数
 */

// @lc code=start
class Solution
{
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
    {
        // 车和皇后在一条横线上，且它们之间没有象
        if (a == e && !(a == c && d > min(b, f) && d < max(b, f)))
            return 1;
        // 车和皇后在一条竖线上，且它们之间没有象
        if (b == f && !(b == d && c > min(a, e) && c < max(a, e)))
            return 1;
        // 象和皇后在一条斜线上，且它们之间没有车
        if ((c + d == e + f && !(a + b == e + f && a > min(c, e) && a < max(c, e))) ||
            (c - d == e - f && !(a - b == e - f && a > min(c, e) && a < max(c, e))))
            return 1;
        return 2;
    }
};
// @lc code=end
