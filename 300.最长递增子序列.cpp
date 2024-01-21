/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start

// 递归

// class Solution
// {
// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         // 特判
//         if (nums.size() == 1)
//             return 1;

//         int n = nums.size();

//         function<int(int)> dfs = [&](int i)
//         {
//             int res = 0;
//             for (int j = 0; j < i; j++)
//                 if (nums[j] < nums[i])
//                     res = max(res, dfs(j));
//             return res + 1;
//         };

//         int ans = 0;
//         for (int i = 0; i < n; i++)
//             ans = max(ans, dfs(i));
//         return ans;
//     }
// };

// 动态规划

// class Solution
// {
// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         // 特判
//         if (nums.size() == 1)
//             return 1;

//         int n = nums.size();
//         // dp[i]: 以 i 结尾的最长递增子序列的长度
//         vector<int> dp(n, 1);
//         // 初始化
//         for (int i = 0; i < n; i++)
//             dp[i] = 1;

//         int maxLength = 0;
//         // 状态转移
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < i; j++)
//             {
//                 if (nums[j] < nums[i])
//                     dp[i] = max(dp[i], dp[j] + 1); // 状态转移方程
//                 maxLength = max(maxLength, dp[i]);
//             }
//         return maxLength;
//     }
// };

// 贪心 + 二分查找

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // 特判
        if (nums.size() == 1)
            return 1;

        int n = nums.size();
        vector<int> g;
        for (int i = 0; i < n; i++)
        {
            int j = lower_bound(g.begin(), g.end(), nums[i]) - g.begin();
            if (j == g.size())
                g.push_back(nums[i]);
            else
                g[j] = nums[i];
        }
        return g.size();
    }
};
// @lc code=end
