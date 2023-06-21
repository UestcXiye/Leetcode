/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] <= nums[i - 1])
                start = i;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
// @lc code=end
