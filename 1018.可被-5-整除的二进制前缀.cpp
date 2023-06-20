/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> ans(n);
        long long num = 0;
        for (int i = 0; i < n; i++)
        {
            // num = 2 * num + nums[i] 会溢出
            num = (2 * num + nums[i]) % 5;
            if (num % 5 == 0)
                ans[i] = true;
            else
                ans[i] = false;
        }
        return ans;
    }
};
// @lc code=end
