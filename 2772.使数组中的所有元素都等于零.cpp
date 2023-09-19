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
        int n = nums.size(), sum_diff = 0;
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            sum_diff += diff[i];
            int x = nums[i] + sum_diff; // x 就是 nums[i] 的实际值
            if (x == 0)
                continue; // 无需操作
            if (x < 0 || i + k > n)
                return false; // 无法操作
            sum_diff -= x;    // 直接加到 sum_diff 中
            diff[i + k] += x;
        }
        return true;
    }
};
// @lc code=end
