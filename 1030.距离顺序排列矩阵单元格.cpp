/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        vector<vector<int>> cells;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cells.push_back({i, j});

        auto cmp = [=](const vector<int> &v1, const vector<int> &v2) -> bool
        {
            int distance1 = abs(v1[0] - rCenter) + abs(v1[1] - cCenter);
            int distance2 = abs(v2[0] - rCenter) + abs(v2[1] - cCenter);
            return distance1 < distance2;
        };

        sort(cells.begin(), cells.end(), cmp);
        return cells;
    }
};
// @lc code=end
