/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start

// Time Limit Exceeded

// class Solution
// {
// public:
//     vector<int> productExceptSelf(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> ans(n, 0);
//         for (int i = 0; i < n; i++)
//         {
//             int product = 1;
//             for (int j = 0; j < n; j++)
//                 if (j != i)
//                     product *= nums[j];
//             ans[i] = product;
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        // L 和 R 分别表示左右两侧的乘积列表
        vector<int> L(n, 0), R(n, 0);
        vector<int> ans(n, 0);
        // L[i] 为索引 i 左侧所有元素的乘积
        // 对于索引为 0 的元素，因为左侧没有元素，所以 L[0] = 1
        L[0] = 1;
        for (int i = 1; i < n; i++)
            L[i] = nums[i - 1] * L[i - 1];
        // R[i] 为索引 i 右侧所有元素的乘积
        // 对于索引为 n-1 的元素，因为右侧没有元素，所以 R[n-1] = 1
        R[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            R[i] = nums[i + 1] * R[i + 1];
        // 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
        for (int i = 0; i < n; i++)
            ans[i] = L[i] * R[i];
        return ans;
    }
};

// 空间优化

// class Solution
// {
// public:
//     vector<int> productExceptSelf(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> ans(n, 0);
//         // ans[i] 表示索引 i 左侧所有元素的乘积
//         // 因为索引为 0 的元素左侧没有元素， 所以 ans[0] = 1
//         ans[0] = 1;
//         for (int i = 1; i < n; i++)
//             ans[i] = nums[i - 1] * ans[i - 1];
//         // R 为右侧所有元素的乘积
//         // 刚开始右边没有元素，所以 R = 1
//         int R = 1;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             // 对于索引 i，左边的乘积为 ans[i]，右边的乘积为 R
//             ans[i] = ans[i] * R;
//             // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
//             R *= nums[i];
//         }
//         return ans;
//     }
// };
// @lc code=end
