/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start

// 排序

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n; i++)
//             if (nums[i] != i)
//                 return i;
//         return n;
//     }
// };

// 哈希

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         unordered_set<int> uset;
//         int n = nums.size(), ans = 0;
//         for (int i = 0; i < n; i++)
//             uset.insert(nums[i]);
//         for (int i = 0; i <= n; i++)
//             if (!uset.count(i))
//                 ans = i;
//         return ans;
//     }
// };

// 数学：高斯求和公式

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         int n = nums.size();
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         return n * (n + 1) / 2 - sum;
//     }
// };

// 位运算

// 性质1：x ^ x = 0
// 性质2：x ^ 0 =  x

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         int n = nums.size();
//         // 数组 nums 有 n 个数，添加从 0 到 n 的每个整数，总共 2n + 1 个整数
//         // 在 2n + 1 个整数中，丢失的数字只出现一次，其余数字均出现两次
//         for (int i = 0; i <= n; i++)
//             nums.push_back(i);
//         int ans = nums[0];
//         // 对 2n + 1 个整数进行按位异或运算，结果即为丢失的数字
//         for (int i = 1; i < 2 * n + 1; i++)
//             ans ^= nums[i];
//         return ans;
//     }
// };

// 位运算-空间优化

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int &num : nums)
            ans ^= num;
        for (int i = 0; i <= n; i++)
            ans ^= i;
        return ans;
    }
};
// @lc code=end
