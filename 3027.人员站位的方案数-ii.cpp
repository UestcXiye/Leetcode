/*
 * @lc app=leetcode.cn id=3027 lang=cpp
 *
 * [3027] 人员站位的方案数 II
 */

// @lc code=start

// 排序 + 枚举

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const auto &p, const auto &q)
             { return p[0] != q[0] ? p[0] < q[0] : p[1] > q[1]; });

        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int y0 = points[i][1];
            int max_y = INT_MIN;
            for (int j = i + 1; j < n; j++)
            {
                int y = points[j][1];
                if (y <= y0 && y > max_y)
                {
                    max_y = y;
                    count++;
                }
            }
        }

        return count;
    }
};
// @lc code=end
