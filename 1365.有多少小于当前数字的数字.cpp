/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (const int &num:nums)
                if (num < nums[i])
                    count++;
            ans[i] = count;
        }
        return ans;
    }
};
// @lc code=end
