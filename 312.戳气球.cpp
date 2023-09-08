/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> rec; // 记忆化数组
    // 主函数
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        // 数组两边各新增数字为 1 的气球
        nums.insert(nums.begin(), 1); // 防止 i - 1 < 0 越界
        nums.push_back(1);            // 防止 j + 1 > n 越界
        rec.resize(n + 2, vector<int>(n + 2, -1));
        return solve(nums, 0, n + 1);
    }
    // 辅函数
    // solve(i, j): 将开区间 (i, j) 内的位置全部填满气球能够得到的最多硬币数
    int solve(vector<int> &nums, int left, int right)
    {
        // 开区间 (left, right) 中没有气球
        if (left >= right - 1)
            return 0; // solve(left, right) = 0
        if (rec[left][right] != -1)
            return rec[left][right];
        // 我们枚举开区间 (i, j) 内的全部位置 mid
        for (int i = left + 1; i < right; i++)
        {
            // mid 为当前区间第一个添加的气球，
            // 该操作能得到的硬币数为 nums[i] * nums[mid] * nums[j]
            int sum = nums[left] * nums[i] * nums[right];
            // 同时我们递归地计算分割出的两区间对 solve(i,j) 的贡献
            sum += solve(nums, left, i) + solve(nums, i, right);
            // 这三项之和的最大值就是solve(i, j)的值
            rec[left][right] = max(rec[left][right], sum);
        }
        return rec[left][right];
    }
};

// 区间DP
// class Solution
// {
// public:
//     int maxCoins(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
//         // dp[i][j]: 戳破区间[i,j]所有气球的获得的最大值
//         nums.insert(nums.begin(), 1); // 防止i-1<0 越界
//         nums.push_back(1);            // 防止j+1>n 越界
//         // 状态转移
//         for (int len = 1; len <= n; len++) // 枚举区间长度
//         {
//             for (int i = 1; i <= n - len + 1; i++) // 枚举左端点
//             {
//                 // 设区间左右端点为i和j, k为[i,j]区间中未被引爆的气球
//                 int j = i + len - 1;         // 计算右端点
//                 for (int k = i; k <= j; k++) // 枚举间断点
//                 {
//                     // 由于[i,k-1]和[k+1,j]内所有气球都爆炸，所以与k相邻的气球为i-1和j+1
//                     dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]); // 状态转移方程
//                 }
//             }
//         }
//         return dp[1][n]; // 戳破[1,n]内所有气球最大值
//     }
// };
// @lc code=end
