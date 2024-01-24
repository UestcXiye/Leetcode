/*
 * @lc app=leetcode.cn id=2772 lang=cpp
 *
 * [2772] 使数组中的所有元素都等于零
 */

// @lc code=start

// 差分数组

class Solution
{
public:
    bool checkArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        // 计算差分数组
        vector<int> diff(n + 1, 0);
        diff[0] = nums[0];
        for (int i = 1; i < n; i++)
            diff[i] = nums[i] - nums[i - 1];
        diff[n] = -nums[n - 1];
        // 从左到右对差分数组里的每个元素进行操作
        for (int i = 0; i + k <= n; i++)
            if (diff[i] > 0)
            {
                diff[i + k] += diff[i];
                diff[i] = 0;
            }
        // 检查差分数组中是否所有元素均为 0
        for (int i = 0; i <= n; i++)
            if (diff[i] != 0)
                return false;
        return true;
    }
};
// @lc code=end
