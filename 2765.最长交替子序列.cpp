/*
 * @lc app=leetcode.cn id=2765 lang=cpp
 *
 * [2765] 最长交替子序列
 */

// @lc code=start

class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = -1;
        auto check = [&](int left, int right)
        {
            int diff = 1;
            for (int i = left + 1; i <= right; i++)
            {
                if (nums[i] - nums[i - 1] != diff)
                    return false;
                diff *= -1;
            }
            return true;
        };
        for (int l = 0; l < n; l++)
            for (int r = l + 1; r < n; r++)
                if (check(l, r))
                    ans = max(ans, r - l + 1);
        return ans;
    }
};
// @lc code=end
