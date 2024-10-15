/*
 * @lc app=leetcode.cn id=3316 lang=cpp
 *
 * [3316] 从原字符串里进行删除操作的最多次数
 */

// @lc code=start
class Solution
{
public:
    int maxRemovals(string source, string pattern, vector<int> &targetIndices)
    {
        int n = source.length();
        int m = pattern.length();

        unordered_set<int> hashSet(targetIndices.begin(), targetIndices.end());
        // dp[i][j] 表示要使 pattern[0,...,j] 是 source[0,...,i] 的子序列，最多的删除次数
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
        // 初始化
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            int is_del = hashSet.count(i);
            dp[i + 1][0] = dp[i][0] + is_del;
        }
        // 状态转移
        for (int i = 0; i < n; i++)
            for (int j = 0; j < min(i + 1, m); j++)
            {
                int is_del = hashSet.count(i);
                dp[i + 1][j + 1] = dp[i][j + 1] + is_del;
                if (source[i] == pattern[j])
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
            }

        return dp[n][m];
    }
};
// @lc code=end
