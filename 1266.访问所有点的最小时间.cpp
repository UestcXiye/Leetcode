/*
 * @lc app=leetcode.cn id=1266 lang=cpp
 *
 * [1266] 访问所有点的最小时间
 */

// @lc code=start
class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int time = 0;
        for (int i = 0; i < points.size() - 1; i++)
        {
            int step = max(abs(points[i + 1][0] - points[i][0]), abs(points[i + 1][1] - points[i][1]));
            time += step;
        }
        return time;
    }
};
// @lc code=end
