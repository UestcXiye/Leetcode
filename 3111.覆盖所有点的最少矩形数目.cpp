/*
 * @lc app=leetcode.cn id=3111 lang=cpp
 *
 * [3111] 覆盖所有点的最少矩形数目
 */

// @lc code=start

// 降维 + 排序 + 贪心

class Solution
{
public:
    int minRectanglesToCoverPoints(vector<vector<int>> &points, int w)
    {
        // 由于矩形的高没有限制，所以我们只需考虑 points 的横坐标。
        sort(points.begin(), points.end(),
             [&](const vector<int> &p1, const vector<int> &p2)
             { return p1[0] < p2[0]; });

        int ans = 0;
        int right = -1; // 矩形的右边界
        for (vector<int> &point : points)
        {
            if (point[0] > right) // 当前点的横坐标超过了矩形的右边界
            {
                ans++;
                // 以 x=point[0] 为左边界新建一个矩形，为了包含最多点，右边界为 point[0] + w
                right = point[0] + w;
            }
        }
        return ans;
    }
};
// @lc code=end
