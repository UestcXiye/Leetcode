/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int cx = max(min(ax2, bx2) - max(ax1, bx1), 0);
        int cy = max(min(ay2, by2) - max(ay1, by1), 0);
        return area1 + area2 - cx * cy;
    }
};
// @lc code=end
