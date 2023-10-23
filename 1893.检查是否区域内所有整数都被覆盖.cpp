/*
 * @lc app=leetcode.cn id=1893 lang=cpp
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 */

// @lc code=start
class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        vector<bool> covered(51, false);
        for (vector<int> &range : ranges)
            for (int i = range[0]; i <= range[1]; i++)
                covered[i] = true;
        for (int i = left; i <= right; i++)
            if (covered[i] == false)
                return false;
        return true;
    }
};
// @lc code=end
