/*
 * @lc app=leetcode.cn id=3152 lang=cpp
 *
 * [3152] 特殊数组 II
 */

// @lc code=start
class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        // 定义一个长为 n−1 的数组 a，其中 a[i] = nums[i] % 2 == nums[i+1] % 2
        // 那么 a 的从 to-1 到 from 的子数组和等于 0，就说明询问的子数组是特殊数组。
        // 计算 a 的前缀和 preSum，可以快速判断子数组和是否为 0
        vector<int> preSum(n, 0);
        for (int i = 1; i < n; i++)
        {
            // 相邻两数的异或和的最低位取反
            int a = !((nums[i] ^ nums[i - 1]) & 1);
            preSum[i] = preSum[i - 1] + a;
        }

        int m = queries.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; i++)
        {
            int from = queries[i][0], to = queries[i][1];
            ans[i] = preSum[to] - preSum[from] == 0;
        }
        return ans;
    }
};
// @lc code=end
