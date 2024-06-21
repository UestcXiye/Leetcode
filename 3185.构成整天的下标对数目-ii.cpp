/*
 * @lc app=leetcode.cn id=3185 lang=cpp
 *
 * [3185] 构成整天的下标对数目 II
 */

// @lc code=start
class Solution
{
public:
    long long countCompleteDayPairs(vector<int> &hours)
    {
        vector<int> cnt(24, 0);
        long long ans = 0LL;
        for (int &hour : hours)
        {
            hour %= 24;
            ans += cnt[(24 - hour) % 24];
            cnt[hour]++;
        }
        return ans;
    }
};
// @lc code=end
