/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size(), n = m ? img[0].size() : 0;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int sum = 0, count = 0;
                for (int ii = i - 1; ii <= i + 1; ii++)
                    for (int jj = j - 1; jj <= j + 1; jj++)
                        if (ii >= 0 && ii < m && jj >= 0 && jj < n)
                        {
                            sum += img[ii][jj];
                            count++;
                        }
                ans[i][j] = sum / count;
            }
        return ans;
    }
};
// @lc code=end
