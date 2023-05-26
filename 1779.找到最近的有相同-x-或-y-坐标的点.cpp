/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int n = points.size();
        int minDistance = __INT_MAX__;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {

            if (points[i][0] == x || points[i][1] == y)
            {
                int distance = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
