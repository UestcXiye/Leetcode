/*
 * @lc app=leetcode.cn id=2249 lang=cpp
 *
 * [2249] 统计圆内格点数目
 */

// @lc code=start
class Solution
{
public:
    int countLatticePoints(vector<vector<int>> &circles)
    {
        // 特判
        if (circles.empty())
            return 0;

        // 求枚举的最大、最小边界
        int min_x = INT_MAX, min_y = INT_MAX;
        int max_x = 0, max_y = 0;
        for (vector<int> &circle : circles)
        {
            int x = circle[0], y = circle[1], r = circle[2];
            min_x = min(min_x, x - r);
            min_y = min(min_y, y - r);
            max_x = max(max_x, x + r);
            max_y = max(max_y, y + r);
        }

        // 枚举点，遇到包含当前点的圆，答案 +1
        int ans = 0;
        for (int i = min_x; i <= max_x; i++)
            for (int j = min_y; j <= max_y; j++)
                for (vector<int> &circle : circles)
                {
                    int x = circle[0], y = circle[1], r = circle[2];
                    if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r)
                    {
                        ans++;
                        break;
                    }
                }
        return ans;
    }
};
// @lc code=end
