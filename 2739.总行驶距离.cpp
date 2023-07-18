/*
 * @lc app=leetcode.cn id=2739 lang=cpp
 *
 * [2739] 总行驶距离
 */

// @lc code=start
class Solution
{
public:
    int distanceTraveled(int mainTank, int additionalTank)
    {
        int totalTank = 0;
        while (mainTank >= 5)
        {
            totalTank += 5;
            mainTank -= 5;
            if (additionalTank > 0)
            {
                additionalTank--;
                mainTank++;
            }
        }
        return 10 * (totalTank + mainTank);
    }
};
// @lc code=end
