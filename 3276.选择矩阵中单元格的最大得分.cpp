/*
 * @lc app=leetcode.cn id=3276 lang=cpp
 *
 * [3276] 选择矩阵中单元格的最大得分
 */

// @lc code=start

// 状压 DP

class Solution
{
public:
    int maxScore(vector<vector<int>> &grid)
    {
        int m = grid.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < m; i++)
        {
            for (int &x : grid[i])
            {
                // 保存所有包含 x 的行号（压缩成二进制数）
                pos[x] |= 1 << i;
            }
        }

        vector<int> all_nums;
        for (auto &[x, _] : pos)
        {
            all_nums.push_back(x);
        }

        int u = 1 << m;
        vector<vector<int>> dp(all_nums.size() + 1, vector<int>(u));
        for (int i = 0; i < all_nums.size(); i++)
        {
            int x = all_nums[i];
            for (int j = 0; j < u; j++)
            {
                dp[i + 1][j] = dp[i][j]; // 不选 x
                for (int t = pos[x], lb; t; t ^= lb)
                {
                    lb = t & -t;       // lb = 1<<k，其中 k 是行号
                    if ((j & lb) == 0) // 没选过第 k 行的数
                    {
                        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j | lb] + x); // 选第 k 行的 x
                    }
                }
            }
        }
        return dp.back()[0];
    }
};

// 回溯

// class Solution
// {
// private:
//     int m, n;
//     int ans = 0;

// public:
//     int maxScore(vector<vector<int>> &grid)
//     {
//         m = grid.size(), n = m ? grid[0].size() : 0;
//         unordered_set<int> s;
//         backtrace(0, 0, s, grid);
//         return ans;
//     }
//     // 辅函数 - 回溯
//     void backtrace(int level, int score, unordered_set<int> s, vector<vector<int>> &grid)
//     {
//         if (level == m)
//         {
//             ans = max(ans, score);
//             return;
//         }
//         for (int j = 0; j < n; j++)
//         {
//             if (s.count(grid[level][j]) == 0)
//             {
//                 s.insert(grid[level][j]);
//                 score += grid[level][j];
//                 backtrace(level + 1, score, s, grid);
//                 score -= grid[level][j];
//                 s.erase(grid[level][j]);
//                 backtrace(level + 1, score, s, grid);
//             }
//         }
//     }
// };
// @lc code=end
