/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        int n = image.size();
        for (vector<int> &line : image)
        {
            reverse(line.begin(), line.end());
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (image[i][j] == 1)
                    image[i][j] = 0;
                else
                    image[i][j] = 1;
            }
        return image;
    }
};
// @lc code=end
