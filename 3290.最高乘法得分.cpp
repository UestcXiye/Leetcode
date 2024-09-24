/*
 * @lc app=leetcode.cn id=3290 lang=cpp
 *
 * [3290] 最高乘法得分
 */

// @lc code=start
class Solution
{
public:
    long long maxScore(vector<int> &a, vector<int> &b)
    {
        int n = b.size();
        // dp[i][j] 表示从 b[0] 到 b[i] 选 j+1 个数，与 a[0] 到 a[j] 计算点积，结果的最大值
        vector<vector<long long>> dp(n + 1, vector<long long>(5));
        // 初始化
        for (int j = 1; j < 5; j++)
            dp[0][j] = (long long)INT_MIN * 20;
        // 状态转移
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < 5; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + (long long)a[j - 1] * b[i - 1]);

        return dp[n][4];
    }
};
// @lc code=end
