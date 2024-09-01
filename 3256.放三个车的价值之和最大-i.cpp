/*
 * @lc app=leetcode.cn id=3256 lang=cpp
 *
 * [3256] 放三个车的价值之和最大 I
 */

// @lc code=start
class Solution
{
public:
    long long maximumValueSum(vector<vector<int>> &board)
    {
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                v.push_back({board[i][j], i, j});
        sort(v.begin(), v.end(), greater<tuple<int, int, int>>());

        long long ans = LONG_LONG_MIN;
        int range = min(2 * (m + n) + 1, (int)v.size());
        for (int i = 0; i < range; i++)
        {
            auto [v1, x1, y1] = v[i];
            for (int j = i + 1; j < range; j++)
            {
                auto [v2, x2, y2] = v[j];
                if (x2 == x1 || y2 == y1)
                    continue;
                for (int k = j + 1; k < range; k++)
                {
                    auto [v3, x3, y3] = v[k];
                    if (x3 == x1 || y3 == y1 || x3 == x2 || y3 == y2)
                        continue;
                    ans = max(ans, (long long)v1 + v2 + v3);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
