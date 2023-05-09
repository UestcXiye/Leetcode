/*
 * @lc app=leetcode.cn id=2639 lang=cpp
 *
 * [2639] 查询网格图中每一列的宽度
 */

// @lc code=start
class Solution
{
public:
    vector<int> findColumnWidth(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // cout << m << " " << n << endl;
        int lens[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int len;
                if (grid[i][j] == 0)
                    len = 1;
                else
                {
                    len = 0;
                    int number = abs(grid[i][j]);
                    while (number)
                    {
                        number /= 10;
                        len++;
                    }
                    if (grid[i][j] < 0)
                        len++;
                }
                lens[i][j] = len;
            }
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //         cout << lens[i][j] << " ";
        //     cout << endl;
        // }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int maxLen = -1;
            for (int j = 0; j < m; j++)
            {
                maxLen = max(maxLen, lens[j][i]);
            }
            ans.push_back(maxLen);
        }
        // for (int i = 0; i < ans.size(); i++)
        //     cout << ans[i] << " ";
        // cout << endl;
        return ans;
    }
};
// @lc code=end
