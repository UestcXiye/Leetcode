/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start

// 动态规划

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        // dp[i] 表示从下标范围 [0,i] 中的任意下标出发可以到达的最大下标
        vector<int> dp(n);
        // 初始化
        dp[0] = nums[0];
        // 状态转移
        for (int i = 1; i < n; i++)
        {
            if (dp[i - 1] < i)
                return false;
            dp[i] = max(dp[i - 1], i + nums[i]);
        }
        return dp[n - 1] >= n - 1;
    }
};

// class Solution
// {
// public:
//     bool canJump(vector<int> &nums)
//     {
//         int n = nums.size();
//         int max_far = 0; // 目前能跳到的最远位置
//         for (int i = 0; i < n; i++)
//         {
//             if (i <= max_far)
//             {
//                 max_far = max(max_far, i + nums[i]);
//                 if (max_far >= n - 1)
//                     return true;
//             }
//         }
//         return false;
//     }
// };
// @lc code=end
