/*
 * @lc app=leetcode.cn id=3200 lang=cpp
 *
 * [3200] 三角形的最大高度
 */

// @lc code=start
class Solution
{
public:
    int maxHeightOfTriangle(int red, int blue)
    {
        if (red <= 0 || blue <= 0)
            return 0;

        return max(helper(red, blue), helper(blue, red));
    }
    // 辅助函数
    int helper(int x, int y)
    {
        int level = 0;
        while (x >= 0 && y >= 0)
        {
            if (level % 2 == 0)
            {
                x -= (level + 1);
                if (x < 0)
                    break;
            }
            else
            {
                y -= (level + 1);
                if (y < 0)
                    break;
            }
            level++;
        }
        return level;
    }
};
// @lc code=end
