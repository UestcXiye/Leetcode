/*
 * @lc app=leetcode.cn id=2760 lang=cpp
 *
 * [2760] 最长奇偶子数组
 */

// @lc code=start
class Solution
{
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 != 0 || nums[i] > threshold)
                continue;
            int left = i, right = i;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j - 1] % 2 != nums[j] % 2 && nums[j] <= threshold)
                    right++;
                else
                    break;
            }
            ans = max(right - left + 1, ans);
        }
        return ans;
    }
};
// @lc code=end
