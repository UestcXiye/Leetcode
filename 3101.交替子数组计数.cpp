/*
 * @lc app=leetcode.cn id=3101 lang=cpp
 *
 * [3101] 交替子数组计数
 */

// @lc code=start

// 分组循环

class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        // 交替子数组的子数组一定是交替子数组
        int n = nums.size();
        long long ans = 0;

        int i = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && nums[j] != nums[j - 1])
                j++;
            int len = j - i; // 当前交替子数组长度
            // 交替子数组的数量 = len * (len + 1) / 2
            ans += (long long)len * (len + 1) / 2;
            i = j;
        }
        return ans;
    }
};
// @lc code=end
