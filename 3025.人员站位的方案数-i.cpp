/*
 * @lc app=leetcode.cn id=3025 lang=cpp
 *
 * [3025] 人员站位的方案数 I
 */

// @lc code=start

// 暴力

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int n = points.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                int x2 = points[j][0], y2 = points[j][1];
                if (x1 <= x2 && y1 >= y2) // 围栏合法
                {
                    bool ok = true;
                    for (int k = 0; k < n; k++)
                    {
                        if (k == i || k == j)
                            continue;
                            
                        int x = points[k][0], y = points[k][1];
                        if (x >= x1 && x <= x2 && y >= y2 && y <= y1)
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                        count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
