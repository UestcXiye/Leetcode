/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start

// 记忆化搜索

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        int memo[n][n];
        memset(memo, -1, sizeof(memo));

        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i > j)
                return 0;
            if (i == j)
                return piles[i];
            int &res = memo[i][j];
            if (res != -1)
                return res;
            res = max(piles[i] - dfs(i + 1, j), piles[j] - dfs(i, j - 1));
            return res;
        };

        return dfs(0, n - 1) > 0;
    }
};

// 动态规划

// class Solution
// {
// public:
//     bool stoneGame(vector<int> &piles)
//     {
//         int n = piles.size();
//         // dp[i][j] 表示在下标范围 [i,j] 中，当前玩家与另一个玩家的石子数量之差的最大值
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         // 初始化
//         for (int i = 0; i < n; i++)
//             dp[i][i] = piles[i];
//         // 状态转移
//         for (int i = n - 2; i >= 0; i--)
//             for (int j = i + 1; j < n; j++)
//                 dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);

//         return dp[0][n - 1] > 0;
//     }
// };
// @lc code=end
