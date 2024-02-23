/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start

// 递归（超时）

// class Solution
// {
// public:
//     int rob(vector<int> &nums)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;

//         int n = nums.size();
//         if (n == 1)
//             return nums[0];

//         function<int(int)> dfs = [&](int i) -> int
//         {
//             if (i < 0)
//                 return 0;

//             int res = max(dfs(i - 1), dfs(i - 2) + nums[i]);
//             return res;
//         };

//         return dfs(n - 1);
//     }
// };

// 递归 + 记忆化搜索

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // 特判
        if (nums.empty())
            return 0;

        int n = nums.size();
        if (n == 1)
            return nums[0];

        int memo[n];
        memset(memo, -1, sizeof(memo));

        function<int(int)> dfs = [&](int i) -> int
        {
            if (i < 0)
                return 0;
            if (memo[i] != -1)
                return memo[i];

            int res = max(dfs(i - 1), dfs(i - 2) + nums[i]);
            memo[i] = res;
            return res;
        };

        return dfs(n - 1);
    }
};

// 动态规划

// class Solution
// {
// public:
//     int rob(vector<int> &nums)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;

//         int n = nums.size();
//         if (n == 1)
//             return nums[0];

//         // dp[i]: 偷窃 nums[0,...,i] 能得到的最高金额
//         vector<int> dp(n, 0);

//         // 初始化
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);

//         // 状态转移
//         for (int i = 2; i < n; i++)
//         {
//             dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//         }

//         return dp[n - 1];
//     }
// };

// 动态规划 - 空间压缩

// class Solution
// {
// public:
//     int rob(vector<int> &nums)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;

//         int n = nums.size();
//         if (n == 1)
//             return nums[0];

//         int pre2 = 0, pre1 = 0, cur;
//         // 状态转移
//         for (int i = 0; i < n; i++)
//         {
//             cur = max(pre2 + nums[i], pre1);
//             pre2 = pre1;
//             pre1 = cur;
//         }
//         return cur;
//     }
// };
// @lc code=end
