/*
 * @lc app=leetcode.cn id=1690 lang=cpp
 *
 * [1690] 石子游戏 VII
 */

// @lc code=start

// 记忆化搜索

// class Solution
// {
// public:
//     int stoneGameVII(vector<int> &stones)
//     {
//         int n = stones.size();
//         vector<int> preSum(n + 1, 0); // 前缀和
//         for (int i = 0; i < n; i++)
//             preSum[i + 1] = preSum[i] + stones[i];
//         vector<vector<int>> memo(n, vector<int>(n, 0));
//         function<int(int, int)> dfs = [&](int i, int j) -> int
//         {
//             if (i >= j) // 递归边界
//                 return 0;
//             if (memo[i][j] != 0) // 之前计算过
//                 return memo[i][j];
//             int res = max(preSum[j + 1] - preSum[i + 1] - dfs(i + 1, j),
//                           preSum[j] - preSum[i] - dfs(i, j - 1));
//             memo[i][j] = res;
//             return res;
//         };

//         return dfs(0, n - 1);
//     }
// };

// 动态规划

class Solution
{
public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> s(n + 1);
        partial_sum(stones.begin(), stones.end(), s.begin() + 1);
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = n - 2; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                f[i][j] = max(s[j + 1] - s[i + 1] - f[i + 1][j], s[j] - s[i] - f[i][j - 1]);

        return f[0][n - 1];
    }
};
// @lc code=end
