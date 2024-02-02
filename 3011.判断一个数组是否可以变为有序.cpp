/*
 * @lc app=leetcode.cn id=3011 lang=cpp
 *
 * [3011] 判断一个数组是否可以变为有序
 */

// @lc code=start
class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;

        // 分组循环
        while (i < n) // 外层循环
        {
            int ones = countOne(nums[i]);
            int start = i;
            // 内层循环
            while (i < n && countOne(nums[i]) == ones)
                i++;
            // 循环结束后 nums[start,...,i) 是一个区间
            sort(nums.begin() + start, nums.begin() + i);
        }
        return is_sorted(nums.begin(), nums.end());
    }
    // 辅函数 - 计算 x 在二进制下数位为 1 的数目
    int countOne(int x)
    {
        int count = 0;
        while (x)
        {
            count += x % 2;
            x /= 2;
        }
        return count;
    }
};
// @lc code=end
