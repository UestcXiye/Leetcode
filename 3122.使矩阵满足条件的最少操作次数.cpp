/*
 * @lc app=leetcode.cn id=3122 lang=cpp
 *
 * [3122] 使矩阵满足条件的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        // cnt[i][x] 表示第 i 列元素 x 的出现次数
        vector<vector<int>> cnt(n, vector<int>(10, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int x = grid[i][j];
                cnt[j][x]++;
            }

        vector<vector<int>> memo(n, vector<int>(11, -1)); // -1 表示没有计算过
        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i < 0)
                return 0;
            auto &res = memo[i][j]; // 注意这里是引用
            if (res != -1)
            { // 之前计算过
                return res;
            }
            res = 0;
            for (int k = 0; k < 10; k++)
            {
                if (k != j)
                    res = max(res, dfs(i - 1, k) + cnt[i][k]);
            }
            return res;
        };

        int maxRemain = dfs(n - 1, 10);
        return m * n - maxRemain;
    }
};
// @lc code=end
