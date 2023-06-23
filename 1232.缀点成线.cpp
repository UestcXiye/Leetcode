/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */

// @lc code=start
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        // 两点式：(y-y1)/(x-x1)=(y-y2)/(x-x2)
        // 这里取定点为coordinates[0],和coordinates[n-1]
        // 为避免除法运算，这里用“两内项的积等于两外项的积”计算
        int n = coordinates.size();
        for (int i = 1; i < n - 1; i++)
        {
            int left = (coordinates[i][0] - coordinates[0][0]) * (coordinates[i][1] - coordinates[n - 1][1]);
            int right = (coordinates[i][1] - coordinates[0][1]) * (coordinates[i][0] - coordinates[n - 1][0]);
            if (left != right)
                return false;
        }
        return true;
    }
};
// @lc code=end
