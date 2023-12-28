/*
 * @lc app=leetcode.cn id=2735 lang=cpp
 *
 * [2735] 收集巧克力
 */

// @lc code=start
class Solution
{
public:
    long long minCost(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<int> f(nums);
        long long ans = accumulate(f.begin(), f.end(), 0LL);
        for (int k = 1; k < n; k++)
        {
            for (int i = 0; i < n; i++)
                f[i] = min(f[i], nums[(i + k) % n]);
            ans = min(ans, (long long)k * x + accumulate(f.begin(), f.end(), 0LL));
        }
        return ans;
    }
};
// @lc code=end
