/*
 * @lc app=leetcode.cn id=2441 lang=cpp
 *
 * [2441] 与对应负数同时存在的最大正整数
 */

// @lc code=start
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return -1;
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i; j < n; j++)
                if (nums[i] != nums[j] && abs(nums[i]) == abs(nums[j]))
                    ans = max(ans, abs(nums[i]));
        }
        return ans;
    }
};
// @lc code=end
