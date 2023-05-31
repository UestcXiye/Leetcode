/*
 * @lc app=leetcode.cn id=1725 lang=cpp
 *
 * [1725] 可以形成最大正方形的矩形数目
 */

// @lc code=start
class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int n = rectangles.size();
        vector<int> sideLengths;
        for (vector<int> &rectangle : rectangles)
            sideLengths.push_back(min(rectangle[0], rectangle[1]));
        int maxLen = 0, number = 0;
        for (int &sideLength : sideLengths)
        {
            if (sideLength > maxLen)
            {
                maxLen = sideLength;
                number = 1;
            }
            else if (sideLength == maxLen)
                number++;
        }
        return number;
    }
};
// @lc code=end
