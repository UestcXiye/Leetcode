/*
 * @lc app=leetcode.cn id=3192 lang=cpp
 *
 * [3192] 使二进制数组全部等于 1 的最少操作次数 II
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1 && ans % 2 == 1)
                ans++;
            if (nums[i] == 0 && ans % 2 == 0)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
