/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] 切割后面积最大的蛋糕
 */

// @lc code=start
class Solution
{
private:
    static const int MOD = 1e9 + 7;

public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int max_row_gap = horizontalCuts[0] - 0;
        for (int i = 1; i < horizontalCuts.size(); i++)
            max_row_gap = max(max_row_gap, horizontalCuts[i] - horizontalCuts[i - 1]);
        max_row_gap = max(max_row_gap, h - horizontalCuts[horizontalCuts.size() - 1]);

        int max_col_gap = verticalCuts[0] - 0;
        for (int i = 1; i < verticalCuts.size(); i++)
            max_col_gap = max(max_col_gap, verticalCuts[i] - verticalCuts[i - 1]);
        max_col_gap = max(max_col_gap, w - verticalCuts[verticalCuts.size() - 1]);

        return (long long)max_row_gap * max_col_gap % MOD;
    }
};
// @lc code=end
