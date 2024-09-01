/*
 * @lc app=leetcode.cn id=3255 lang=cpp
 *
 * [3255] 长度为 K 的子数组的能量值 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0; // 连续递增的元素个数
        vector<int> ans(n - k + 1, -1);
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || nums[i] == nums[i - 1] + 1)
                cnt++;
            else
                cnt = 1;
            if (cnt >= k)
                ans[i - k + 1] = nums[i];
        }
        return ans;
    }
};
// @lc code=end
