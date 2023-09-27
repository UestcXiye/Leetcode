/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        if (ops.empty())
            return m * n;
        int min_x = __INT_MAX__, min_y = __INT_MAX__;
        for (vector<int> &op : ops)
        {
            min_x = min(min_x, op[0]);
            min_y = min(min_y, op[1]);
        }
        return min_x * min_y;
    }
};
// @lc code=end
