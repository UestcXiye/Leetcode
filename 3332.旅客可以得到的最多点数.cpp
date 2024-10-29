/*
 * @lc app=leetcode.cn id=3332 lang=cpp
 *
 * [3332] 旅客可以得到的最多点数
 */

// @lc code=start
class Solution
{
public:
    int maxScore(int n, int k, vector<vector<int>> &stayScore, vector<vector<int>> &travelScore)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        // 状态转移
        for (int i = 1; i <= k; i++)
            for (int j = 0; j < n; j++)
            {
                // 留在当前城市 j
                dp[i][j] = dp[i - 1][j] + stayScore[i - 1][j];
                // 来自另外一座城市 d
                for (int d = 0; d < n; d++)
                    dp[i][j] = max(dp[i][j], dp[i - 1][d] + travelScore[d][j]);
            }

        int ans = INT_MIN;
        // 枚举城市 i 作为终点
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[k][i]);

        return ans;
    }
};
// @lc code=end
