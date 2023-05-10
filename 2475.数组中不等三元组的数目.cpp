/*
 * @lc app=leetcode.cn id=2475 lang=cpp
 *
 * [2475] 数组中不等三元组的数目
 */

// @lc code=start
class Solution
{
public:
    int unequalTriplets(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (i < j && j < k && i < k)
                        if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k])
                            ans++;
        return ans;
    }
};
// @lc code=end
