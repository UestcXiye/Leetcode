/*
 * @lc app=leetcode.cn id=3191 lang=cpp
 *
 * [3191] 使二进制数组全部等于 1 的最少操作次数 I
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] == 0)
            {
                nums[i + 1] = (nums[i + 1] ? 0 : 1);
                nums[i + 2] = (nums[i + 2] ? 0 : 1);
                ans++;
            }
        }
        if (nums[n - 2] == 0 || nums[n - 1] == 0)
            return -1;
        return ans;
    }
};
// @lc code=end
