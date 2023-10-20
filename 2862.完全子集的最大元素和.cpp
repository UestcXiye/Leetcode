/*
 * @lc app=leetcode.cn id=2862 lang=cpp
 *
 * [2862] 完全子集的最大元素和
 */

// @lc code=start
// class Solution
// {
// public:
//     long long maximumSum(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<long long> sum(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//             sum[core(i)] += nums[i - 1];
//         return *max_element(sum.begin(), sum.end());
//     }
//     // 辅函数 - 得到 n 除去完全平方因子后的剩余结果 res
//     int core(int n)
//     {
//         int res = 1;
//         for (int i = 2; i * i <= n; i++)
//         {
//             int count = 0;
//             while (n % i == 0)
//             {
//                 count++;
//                 n /= i;
//             }
//             if (count % 2 == 1)
//                 res *= i;
//         }
//         if (n > 1)
//             res *= n;
//         return res;
//     }
// };

class Solution
{
public:
    long long maximumSum(vector<int> &nums)
    {
    }
};

// @lc code=end
