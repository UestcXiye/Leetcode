/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // 特判
        if (envelopes.empty())
            return 0;

        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(),
             [&](const auto &e1, const auto &e2)
             {
                 return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
             });
        // dp[i]: 前 i 个元素能组成的最长严格递增子序列的长度
        // vector<int> dp(n, 1);
        // for (int i = 1; i < n; i++)
        //     for (int j = 0; j < i; j++)
        //         if (envelopes[j][1] < envelopes[i][1])
        //             dp[i] = max(dp[i], dp[j] + 1);
        // return *max_element(dp.begin(), dp.end());
        vector<int> f = {envelopes[0][1]};
        for (int i = 1; i < n; ++i)
        {
            if (int num = envelopes[i][1]; num > f.back())
                f.push_back(num);
            else
            {
                auto it = lower_bound(f.begin(), f.end(), num);
                *it = num;
            }
        }
        return f.size();
    }
};
// @lc code=end
