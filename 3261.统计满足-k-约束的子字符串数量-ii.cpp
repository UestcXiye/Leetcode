/*
 * @lc app=leetcode.cn id=3261 lang=cpp
 *
 * [3261] 统计满足 K 约束的子字符串数量 II
 */

// @lc code=start
class Solution
{
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>> &queries)
    {
        int n = s.length();
        vector<int> left(n);
        vector<long long> sum(n + 1);
        int cnt[2]{}, l = 0;

        for (int i = 0; i < n; i++)
        {
            cnt[s[i] & 1]++;
            while (cnt[0] > k && cnt[1] > k)
            {
                cnt[s[l++] & 1]--;
            }
            left[i] = l;
            // 计算 i-left[i]+1 的前缀和
            sum[i + 1] = sum[i] + i - l + 1;
        }

        vector<long long> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0], r = queries[i][1];
            int j = lower_bound(left.begin() + l, left.begin() + r + 1, l) - left.begin();
            ans[i] = sum[r + 1] - sum[j] + (long long)(j - l + 1) * (j - l) / 2;
        }
        return ans;
    }
};
// @lc code=end
