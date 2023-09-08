/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start

// 失败的想法

// class Solution
// {
// public:
//     int findTargetSumWays(vector<int> &nums, int target)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;
//         if (nums.size() == 1 && nums[0] == target)
//             return 1;
//         int n = nums.size(), maxLen = accumulate(nums.begin(), nums.end(), 0);
//         // 状态矩阵
//         vector<vector<int>> dp(n, vector<int>(maxLen, 0));
//         // dp[i,j]: 用数组nums的前i个数字，计算得到j的表达式的数目
//         //  状态转移
//     }
// };

// 0-1背包

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // 特判
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
        {
            if (nums[0] == target || nums[0] == -target)
                return 1;
            else
                return 0;
        }
        int n = nums.size();
        // 数组的元素和为 sum
        // 添加-号的元素之和为 neg，则其余添加+的元素之和为 sum−neg
        // 要使得(sum−neg)-neg=target，于是 neg = (sum-target)/2
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 由于数组中的元素都是非负整数，所以上式成立的前提是sum-target为非负偶数
        if (sum - target < 0 || (sum - target) % 2 != 0)
            return 0;
        // 于是问题转变为：在数组中选取若干数，使得这些元素之和等于neg
        int neg = (sum - target) / 2;
        // 状态矩阵
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1, 0));
        // dp[i,j]: 用数组nums的前i个数字，求和得到j的方案的数目
        // 初始化
        dp[0][0] = 1;
        //  状态转移
        for (int i = 1; i <= n; i++)
        {
            int w = nums[i - 1];
            for (int j = 0; j <= neg; j++)
            {
                if (j >= w)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - w];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][neg];
    }
};

// 空间优化

// class Solution
// {
// public:
//     int findTargetSumWays(vector<int> &nums, int target)
//     {
//         // 特判
//         if (nums.empty())
//             return 0;
//         if (nums.size() == 1)
//         {
//             if (nums[0] == target || nums[0] == -target)
//                 return 1;
//             else
//                 return 0;
//         }
//         int n = nums.size();
//         // 数组的元素和为 sum
//         // 添加-号的元素之和为 neg，则其余添加+的元素之和为 sum−neg
//         // 要使得(sum−neg)-neg=target，于是 neg = (sum-target)/2
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         // 由于数组中的元素都是非负整数，
//         // 所以上式成立的前提是sum-target为非负偶数
//         if (sum - target < 0 || (sum - target) % 2 != 0)
//             return 0;
//         // 于是问题转变为：在数组中选取若干数，使得这些元素之和等于neg
//         int neg = (sum - target) / 2;
//         // 状态矩阵
//         vector<int> dp(neg + 1, 0);
//         // 初始化
//         dp[0] = 1;
//         // 状态转移
//         for (int i = 1; i <= n; i++)
//         {
//             int w = nums[i - 1];
//             for (int j = neg; j >= w; j--)
//                 dp[j] += dp[j - w];
//         }
//         return dp[neg];
//     }
// };
// @lc code=end
