/*
 * @lc app=leetcode.cn id=2860 lang=cpp
 *
 * [2860] 让所有学生保持开心的分组方法数
 */

// @lc code=start
class Solution
{
public:
    int countWays(vector<int> &nums)
    {
        int n = nums.size();
        int way = 0; // 分组方法的数目
        sort(nums.begin(), nums.end());
        // 枚举选中学生个数
        for (int i = 0; i <= n; i++)
        {
            if (i == 0) // 不选学生
            {
                // 将 0 与数组的最小值（nums[0]）比较
                if (0 < nums[0])
                    way++;
            }
            else if (i == n) // 全选学生
            {
                // 将 n 与数组的最大值（nums[n - 1]）比较
                if (n > nums[n - 1])
                    way++;
            }
            else // 选中 前 i（1 ~ n - 1） 个学生
            {
                // 选中学生的最大值为 nums[i - 1]，未选中学生的最小值为 nums[i]
                // i 必须位于 (nums[i - 1], nums[i]) 才行
                if (i > nums[i - 1] && i < nums[i])
                    way++;
            }
        }
        return way;
    }
};
// @lc code=end
