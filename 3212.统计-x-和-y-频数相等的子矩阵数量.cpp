/*
 * @lc app=leetcode.cn id=3212 lang=cpp
 *
 * [3212] 统计 X 和 Y 频数相等的子矩阵数量
 */

// @lc code=start
class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        vector<vector<pair<int, int>>> sum(m + 1, vector(n + 1, pair<int, int>()));

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                sum[i + 1][j + 1].first = sum[i + 1][j].first + sum[i][j + 1].first - sum[i][j].first;
                sum[i + 1][j + 1].second = sum[i + 1][j].second + sum[i][j + 1].second - sum[i][j].second;
                if (grid[i][j] == 'X')
                    sum[i + 1][j + 1].first++;
                else if (grid[i][j] == 'Y')
                    sum[i + 1][j + 1].second++;
                if (sum[i + 1][j + 1].first && sum[i + 1][j + 1].first == sum[i + 1][j + 1].second)
                    ans++;
            }
        return ans;
    }
};
// @lc code=end
