/*
 * @lc app=leetcode.cn id=2826 lang=cpp
 *
 * [2826] 将三个组排序
 */

// @lc code=start

// 最长递增子序列，贪心 + 二分查找

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        // 特判
        if (nums.empty())
            return 0;

        int n = nums.size();
        vector<int> g; // 最长递增子序列
        for (int i = 0; i < n; i++)
        {
            int j = upper_bound(g.begin(), g.end(), nums[i]) - g.begin();
            if (j == g.size())
                g.push_back(nums[i]);
            else
                g[j] = nums[i];
        }
        return n - g.size();
    }
};

// 状态机 DP

// class Solution
// {
// public:
//     int minimumOperations(vector<int> &nums)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;

//         int n = nums.size();
//         // dp[i+1][j]: 考虑 nums[0] 到 nums[i]，且 nums[i] 变成 j 的最小修改次数
//         vector<vector<int>> dp(n + 1, vector<int>(4, 0));
//         // 状态转移
//         for (int i = 0; i < n; i++)
//             for (int j = 1; j <= 3; j++)
//             {
//                 dp[i + 1][j] = INT_MAX;
//                 for (int k = 1; k <= j; k++)
//                     dp[i + 1][j] = min(dp[i + 1][j], dp[i][k]);
//                 dp[i + 1][j] += nums[i] != j;
//             }
//         return *min_element(dp[n].begin() + 1, dp[n].end());
//     }
// };

// @lc code=end
