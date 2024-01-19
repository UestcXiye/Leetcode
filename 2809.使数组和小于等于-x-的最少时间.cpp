/*
 * @lc app=leetcode.cn id=2809 lang=cpp
 *
 * [2809] 使数组和小于等于 x 的最少时间
 */

// @lc code=start
class Solution
{
public:
    int minimumTime(vector<int> &nums1, vector<int> &nums2, int x)
    {
        int n = nums1.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++)
        {
            a.push_back({nums2[i], nums1[i]});
        }
        sort(a.begin(), a.end());
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j > 0; j--)
            {
                dp[j] = max(dp[j], dp[j - 1] + a[i].second + a[i].first * j);
            }
        }
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int i = 0; i <= n; i++)
        {
            if (s1 + s2 * i - dp[i] <= x)
                return i;
        }
        return -1;
    }
};
// @lc code=end
