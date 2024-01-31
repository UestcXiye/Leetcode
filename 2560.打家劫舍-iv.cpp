/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start

// 二分答案 + 动态规划

// class Solution
// {
// public:
//     int minCapability(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         int left = *min_element(nums.begin(), nums.end());
//         int right = *max_element(nums.begin(), nums.end());

//         // mx 是二分猜测的窃取能力
//         auto check = [&](int mx, int k) -> bool
//         {
//             // dp[i]: 从 nums[0, i] 中偷金额不超过 mx 的房屋，最多能偷多少间房屋
//             vector<long long> dp(n, 0);
//             // 初始化
//             dp[0] = nums[0] <= mx ? 1 : 0;
//             if (dp[0] || nums[1] <= mx)
//                 dp[1] = 1;
//             // 状态转移
//             for (int i = 2; i < n; i++)
//             {
//                 if (nums[i] > mx)
//                     dp[i] = dp[i - 1];
//                 else
//                     dp[i] = max(dp[i - 1], dp[i - 2] + 1);
//             }
//             return dp[n - 1] >= k;
//         };

//         while (left < right)
//         {
//             int mid = left + (right - left) / 2;
//             if (check(mid, k))
//                 right = mid;
//             else
//                 left = mid + 1;
//         }
//         return left;
//     }
// };

// 二分答案 + 贪心

class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        // mx 是二分猜测的窃取能力
        auto check = [&](int mx, int k) -> bool
        {
            int count = 0;
            for (int i = 0; i < n; i++)
                if (nums[i] <= mx)
                {
                    count++;
                    i++; // 跳过下一间房子
                }
            return count >= k;
        };

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (check(mid, k))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end
