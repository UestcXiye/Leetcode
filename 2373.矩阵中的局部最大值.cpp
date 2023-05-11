/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 *
 * [2373] 矩阵中的局部最大值
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, -1));
        for (int i = 0; i < n - 2; i++)
            for (int j = 0; j < n - 2; j++)
                for (int x = i; x < i + 3; x++)
                    for (int y = j; y < j + 3; y++)
                        maxLocal[i][j] = max(maxLocal[i][j], grid[x][y]);
        return maxLocal;
    }
};
// @lc code=end
