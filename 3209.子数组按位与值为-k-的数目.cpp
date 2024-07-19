/*
 * @lc app=leetcode.cn id=3209 lang=cpp
 *
 * [3209] 子数组按位与值为 K 的数目
 */

// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            for (int j = i - 1; j >= 0 && (nums[j] & x) != nums[j]; j--)
            {
                nums[j] &= x;
            }
            ans += upper_bound(nums.begin(), nums.begin() + i + 1, k) -
                   lower_bound(nums.begin(), nums.begin() + i + 1, k);
        }
        return ans;
    }
};
// @lc code=end
