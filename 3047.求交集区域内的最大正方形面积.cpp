/*
 * @lc app=leetcode.cn id=3047 lang=cpp
 *
 * [3047] 求交集区域内的最大正方形面积
 */

// @lc code=start
class Solution
{
public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
    {
        int n = bottomLeft.size();
        long long ans = 0LL;
        for (int i = 0; i < n - 1; i++)
        {
            auto &b1 = bottomLeft[i];
            auto &t1 = topRight[i];
            for (int j = i + 1; j < n; j++)
            {
                auto &b2 = bottomLeft[j];
                auto &t2 = topRight[j];

                int w = min(t1[0], t2[0]) - max(b1[0], b2[0]);
                int h = min(t1[1], t2[1]) - max(b1[1], b2[1]);
                // 正方形的边长是交集矩形的较短边长
                int size = min(w, h);
                if (size > 0)
                    ans = max(ans, (long long)size * size);
            }
        }
        return ans;
    }
};
// @lc code=end
