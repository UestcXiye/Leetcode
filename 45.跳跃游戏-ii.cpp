/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

// 动态规划

// class Solution
// {
// public:
//     int jump(vector<int> &nums)
//     {
//         int n = nums.size();
//         // dp[i] 表示到达 i 的最少跳数
//         vector<int> dp(n, INT_MAX);
//         // 初始化
//         dp[0] = 0;
//         // 状态转移
//         for (int i = 1; i < n; i++)
//         {
//             for (int j = 0; j < i; j++)
//                 if (j + nums[j] >= i)
//                     dp[i] = min(dp[i], dp[j] + 1);
//         }
//         return dp[n - 1];
//     }
// };

// 动态规划 + 贪心

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        // dp[i] 表示到达 i 的最少跳数
        vector<int> dp(n, INT_MAX);
        // 初始化
        dp[0] = 0;
        // 状态转移
        for (int i = 1, last = 0; i < n; i++)
        {
            // 找到第一个能跳到 i 的点 last
            while (last < n && last + nums[last] < i)
                last++;
            // 使用点 last 更新 dp[i]
            dp[i] = min(dp[i], dp[last] + 1);
        }
        return dp[n - 1];
    }
};

// 贪心 - 反向查找出发位置

// class Solution
// {
// public:
//     int jump(vector<int> &nums)
//     {
//         int pos = nums.size() - 1, steps = 0;
//         while (pos > 0)
//         {
//             // 选择距离最后一个位置最远的那个位置
//             for (int i = 0; i < pos; i++)
//                 if (i + nums[i] >= pos)
//                 {
//                     pos = i;
//                     steps++;
//                     break;
//                 }
//         }
//         return steps;
//     }
// };

// 贪心 - 正向查找可到达的最大位置

// class Solution
// {
// public:
//     int jump(vector<int> &nums)
//     {
//         int max_far = 0; // 目前能跳到的最远位置
//         int step = 0;    // 跳跃次数
//         int end = 0;     // 上次跳跃可达范围右边界（下次的最右起跳点）
//         for (int i = 0; i < nums.size() - 1; i++)
//         {
//             max_far = max(max_far, i + nums[i]);
//             // 到达上次跳跃能到达的右边界了
//             if (i == end)
//             {
//                 end = max_far; // 目前能跳到的最远位置变成了下次的最右起跳点
//                 step++;        // 进入下一次跳跃
//             }
//         }
//         return step;
//     }
// };
// @lc code=end
