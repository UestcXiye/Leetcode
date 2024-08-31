/*
 * @lc app=leetcode.cn id=3242 lang=cpp
 *
 * [3242] 设计相邻元素求和服务
 */

// @lc code=start
class NeighborSum
{
private:
    int g[12][12];
    int n;

public:
    NeighborSum(vector<vector<int>> &grid) : n(grid.size())
    {
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= n + 1; j++)
                g[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = grid[i - 1][j - 1];
    }

    int adjacentSum(int value)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][j] == value)
                    ans = g[i][j - 1] + g[i + 1][j] + g[i - 1][j] + g[i][j + 1];

        return ans;
    }

    int diagonalSum(int value)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][j] == value)
                    ans = g[i - 1][j - 1] + g[i - 1][j + 1] + g[i + 1][j - 1] + g[i + 1][j + 1];
        return ans;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
// @lc code=end
