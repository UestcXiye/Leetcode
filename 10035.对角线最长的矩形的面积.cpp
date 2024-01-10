/*
 * @lc app=leetcode.cn id=10035 lang=cpp
 *
 * [10035] 对角线最长的矩形的面积
 */

// @lc code=start
class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        // 特判
        if (dimensions.empty())
            return 0;

        double maxDiagonal = 0.0;
        int maxArea = 0;
        for (vector<int> &dimension : dimensions)
        {
            int length = dimension[0], width = dimension[1];
            if (sqrt(length * length + width * width) > maxDiagonal)
            {
                maxDiagonal = sqrt(length * length + width * width);
                maxArea = length * width;
            }
            else if (sqrt(length * length + width * width) == maxDiagonal)
                maxArea = max(maxArea, length * width);
        }
        return maxArea;
    }
};
// @lc code=end
