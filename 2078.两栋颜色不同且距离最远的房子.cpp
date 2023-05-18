/*
 * @lc app=leetcode.cn id=2078 lang=cpp
 *
 * [2078] 两栋颜色不同且距离最远的房子
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int n = colors.size();
        int maxDistance = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (colors[i] != colors[j])
                    maxDistance = max(maxDistance, abs(i - j));
        return maxDistance;
    }
};
// @lc code=end
