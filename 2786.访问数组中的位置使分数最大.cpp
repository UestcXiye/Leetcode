/*
 * @lc app=leetcode.cn id=2786 lang=cpp
 *
 * [2786] 访问数组中的位置使分数最大
 */

// @lc code=start

// 动态规划

// class Solution
// {
// public:
//     long long maxScore(vector<int> &nums, int x)
//     {
//         // 特判
//         if (nums.empty())
//             return 0LL;
//         if (x == 0)
//             return accumulate(nums.begin(), nums.end(), 0LL);

//         int n = nums.size();
//         // 状态数组
//         // dp[i][0]: 访问下标范围 [0, i] 中的元素且最后访问的元素是偶数时的最大得分
//         // dp[i][1]: 访问下标范围 [0, i] 中的元素且最后访问的元素是奇数时的最大得分
//         vector<vector<long long>> dp(n, vector<long long>(2, 0));
//         // 初始化
//         if (nums[0] % 2)
//         {
//             dp[0][0] = nums[0] - x;
//             dp[0][1] = nums[0];
//         }
//         else
//         {
//             dp[0][0] = nums[0];
//             dp[0][1] = nums[0] - x;
//         }
//         // 状态转移
//         for (int i = 1; i < n; i++)
//         {
//             if (nums[i] % 2)
//             {
//                 dp[i][0] = dp[i - 1][0];
//                 dp[i][1] = max(dp[i - 1][0] - x, dp[i - 1][1]) + nums[i];
//             }
//             else
//             {
//                 dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - x) + nums[i];
//                 dp[i][1] = dp[i - 1][1];
//             }
//         }
//         return max(dp[n - 1][0], dp[n - 1][1]);
//     }
// };

// 动态规划 - 空间优化

class Solution
{
public:
    long long maxScore(vector<int> &nums, int x)
    {
        // 特判
        if (nums.empty())
            return 0LL;
        if (x == 0)
            return accumulate(nums.begin(), nums.end(), 0LL);

        int n = nums.size();
        long long odd = nums[0] % 2 ? nums[0] : INT_MIN;  // 奇数
        long long even = nums[0] % 2 ? INT_MIN : nums[0]; // 偶数
        // 状态转移
        for (int i = 1; i < n; i++)
        {
            if (nums[i] % 2)
                odd = max(odd, even - x) + nums[i];
            else
                even = max(odd - x, even) + nums[i];
        }
        return max(odd, even);
    }
};
// @lc code=end
