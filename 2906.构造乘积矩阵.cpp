/*
 * @lc app=leetcode.cn id=2906 lang=cpp
 *
 * [2906] 构造乘积矩阵
 */

// @lc code=start

// 前后缀分解
// 同 LeetCode 238

class Solution
{
private:
    const int MOD = 12345;

public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return {};
        int n = grid.size(), m = n ? grid[0].size() : 0;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        // L 和 R 分别表示左右两侧的乘积列表
        vector<vector<int>> L(n, vector<int>(m, 0)), R(n, vector<int>(m, 0));
        long prev = 1; // 前缀乘积
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                L[i][j] = prev;
                prev = prev * grid[i][j] % MOD;
            }
        long suffix = 1; // 后缀乘积
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
            {
                R[i][j] = suffix;
                suffix = suffix * grid[i][j] % MOD;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j] = L[i][j] * R[i][j] % MOD;
        return ans;
    }
};
// @lc code=end
