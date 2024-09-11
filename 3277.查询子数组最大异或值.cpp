/*
 * @lc app=leetcode.cn id=3277 lang=cpp
 *
 * [3277] 查询子数组最大异或值
 */

// @lc code=start
class Solution
{
public:
    vector<int> maximumSubarrayXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> mx(n, vector<int>(n));
        // 初始化
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
            mx[i][i] = nums[i];
        }
        // 状态转移
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = dp[i][j - 1] ^ dp[i + 1][j];
                mx[i][j] = max(dp[i][j], max(mx[i + 1][j], mx[i][j - 1]));
            }

        vector<int> ans;
        for (vector<int> &q : queries)
            ans.push_back(mx[q[0]][q[1]]);

        return ans;
    }
};
// @lc code=end
