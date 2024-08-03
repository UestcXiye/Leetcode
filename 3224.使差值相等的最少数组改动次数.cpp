/*
 * @lc app=leetcode.cn id=3224 lang=cpp
 *
 * [3224] 使差值相等的最少数组改动次数
 */

// @lc code=start
class Solution
{
public:
    int minChanges(vector<int> &nums, int k)
    {
        vector<int> cnt(k + 1), cnt2(k + 1);
        int n = nums.size();
        for (int i = 0; i < n / 2; i++)
        {
            int p = nums[i], q = nums[n - 1 - i];
            if (p > q)
            { // 保证 p <= q
                swap(p, q);
            }
            cnt[q - p]++;
            cnt2[max(q, k - p)]++;
        }

        int ans = n;
        int sum2 = 0; // 统计有多少对 (p,q) 都要改
        for (int x = 0; x <= k; x++)
        {
            // 其他 n/2-cnt[x] 对 (p,q) 至少要改一个数，在此基础上，有额外的 sum2 对 (p,q) 还要再改一个数
            ans = min(ans, n / 2 - cnt[x] + sum2);
            // 对于后面的更大的 x，当前的这 cnt2[x] 对 (p,q) 都要改
            sum2 += cnt2[x];
        }
        return ans;
    }
};
// @lc code=end
