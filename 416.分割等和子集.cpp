/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
// class Solution
// {
// public:
//     // 0-1背包问题
//     bool canPartition(vector<int> &nums)
//     {
//         if (nums.empty())
//             return false;
//         int n = nums.size();
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if (sum % 2 == 1)
//             return false;
//         int target = sum / 2;
//         // 状态数组，并初始化
//         vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
//         // dp[i,j]：前i个数字、总和不超过j的情况下，能否满足j == target
//         dp[0][0] = true;
//         // 状态转移
//         for (int i = 1; i <= n; i++)
//             for (int j = 1; j <= target; j++)
//             {
//                 int w = nums[i - 1];
//                 if (j >= w)
//                     dp[i][j] = dp[i - 1][j] || dp[i - 1][j - w];
//                 else
//                     dp[i][j] = dp[i - 1][j];
//             }
//         return dp[n][target];
//     }
// };

// 空间压缩
class Solution
{
public:
    // 0-1背包问题
    bool canPartition(vector<int> &nums)
    {
        if (nums.empty())
            return false;
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        // 状态数组，并初始化
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        // 状态转移
        for (int i = 1; i <= n; i++)
        {
            int w = nums[i - 1];
            for (int j = target; j >= w; j--)
                dp[j] = dp[j] || dp[j - w]; // 状态转移方程
        }

        return dp[target];
    }
};
// @lc code=end
