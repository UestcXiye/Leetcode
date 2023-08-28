/*
 * @lc app=leetcode.cn id=2833 lang=cpp
 *
 * [2833] 距离原点最远的点
 */

// @lc code=start
class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int left = 0, right = 0, underline = 0;
        for (char &c : moves)
        {
            if (c == 'L')
                left++;
            else if (c == 'R')
                right++;
            else
                underline++;
        }
        return abs(left - right) + underline;
    }
};
// @lc code=end
