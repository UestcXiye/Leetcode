/*
 * @lc app=leetcode.cn id=2849 lang=cpp
 *
 * [2849] 判断能否在给定时间到达单元格
 */

// @lc code=start
class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        if (t == 1 && sx == fx && sy == fy)
            return false;
        return abs(sx - fx) <= t && abs(sy - fy) <= t;
    }
};
// @lc code=end
