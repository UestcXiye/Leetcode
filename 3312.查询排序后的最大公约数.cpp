/*
 * @lc app=leetcode.cn id=3312 lang=cpp
 *
 * [3312] 查询排序后的最大公约数
 */

// @lc code=start
class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt(mx + 1, 0);
        for (int &num : nums)
            cnt[num]++;

        vector<long long> cnt_gcd(mx + 1, 0);
        for (int i = mx; i > 0; i--)
        {
            int c = 0;
            for (int j = i; j <= mx; j += i)
            {
                c += cnt[j];
                // gcd 是 2i,3i,4i,... 的数对不能统计进来
                cnt_gcd[i] -= cnt_gcd[j];
            }
            // c 个数选 2 个，组成 c * (c - 1) / 2 个数对
            cnt_gcd[i] += (long long)c * (c - 1) / 2;
        }

        vector<long long> preSum(mx + 1);
        preSum[0] = cnt_gcd[0];
        for (int i = 1; i < preSum.size(); i++)
            preSum[i] = preSum[i - 1] + cnt_gcd[i];

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
            ans[i] = upper_bound(preSum.begin(), preSum.end(), queries[i]) - preSum.begin();

        return ans;
    }
};
// @lc code=end
