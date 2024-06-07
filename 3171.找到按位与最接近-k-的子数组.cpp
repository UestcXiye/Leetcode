/*
 * @lc app=leetcode.cn id=3171 lang=cpp
 *
 * [3171] 找到按位与最接近 K 的子数组
 */

// @lc code=start
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            ans = min(ans, abs(x - k));
            for (int j = i - 1; j >= 0; j--)
            {
                if ((nums[j] & x) == nums[j])
                    break;
                nums[j] &= x;
                ans = min(ans, abs(nums[j] - k));
            }
        }
        return ans;
    }
};
// @lc code=end
