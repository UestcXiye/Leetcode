/*
 * @lc app=leetcode.cn id=2845 lang=cpp
 *
 * [2845] 统计趣味子数组的数目
 */

// @lc code=start
class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        int n = nums.size();
        vector<int> fun(n, 0);
        for (int i = 0; i < n; i++)
            if (nums[i] % modulo == k)
                fun[i] = 1;
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            preSum[i] = preSum[i - 1] + fun[i - 1];
        long long ans = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1; // 把 preSum[0] = 0 算进去
        for (int right = 0; right < n; right++)
        {
            ans += cnt[(preSum[right + 1] - k + modulo) % modulo];
            cnt[preSum[right + 1] % modulo]++;
        }
        return ans;
    }
};
// @lc code=end
