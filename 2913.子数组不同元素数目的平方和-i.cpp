/*
 * @lc app=leetcode.cn id=2913 lang=cpp
 *
 * [2913] 子数组不同元素数目的平方和 I
 */

// @lc code=start
class Solution
{
private:
    static const int MOD = 1e9 + 7;

public:
    int sumCounts(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> us;
            for (int j = i; j < n; j++)
            {
                us.insert(nums[j]);
                int size = us.size();
                ans = (ans + 1LL * size * size) % MOD;
            }
        }
        return ans;
    }
};
// @lc code=end
