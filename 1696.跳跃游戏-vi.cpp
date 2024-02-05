/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 *
 * [1696] 跳跃游戏 VI
 */

// @lc code=start

// 动态规划（Time Limit Exceeded）

// class Solution
// {
// public:
//     int maxResult(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         // dp[i]: nums[0,...,i] 的最大得分
//         vector<int> dp(n);
//         // 初始化
//         dp[0] = nums[0];
//         // 状态转移
//         for (int i = 1; i < n; i++)
//             dp[i] = *max_element(dp.begin() + max(i - k, 0), dp.begin() + i) + nums[i];

//         return dp[n - 1];
//     }
// };

// 动态规划 + 双端队列

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        // dp[i]: nums[0,...,i] 的最大得分
        vector<int> dp(n);
        // 初始化
        dp[0] = nums[0];
        // 队首就是转移来源最大值的下标
        deque<int> dq;
        dq.push_back(0);
        // 状态转移
        for (int i = 1; i < n; i++)
        {
            // 队列头部的下标超过了 k 的范围，移除
            if (dq.front() < i - k)
                dq.pop_front();
            // 更新 dp[i]，取队列头部的最大 dp 值
            dp[i] = dp[dq.front()] + nums[i];
            // 保持队列中的下标对应的 dp 值是递减的
            while (!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[n - 1];
    }
};
// @lc code=end
