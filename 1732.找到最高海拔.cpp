/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int largestAltitude = 0, currentAltitude = 0;
        for (int altitude : gain)
        {
            currentAltitude += altitude;
            largestAltitude = max(largestAltitude, currentAltitude);
        }
        return largestAltitude;
    }
};
// @lc code=end
