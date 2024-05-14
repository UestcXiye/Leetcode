/*
 * @lc app=leetcode.cn id=3144 lang=cpp
 *
 * [3144] 分割字符频率相等的最少子字符串
 */

// @lc code=start
class Solution
{
public:
    int minimumSubstringsInPartition(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        int cnt[26];
        for (int i = 1; i <= n; i++)
        {
            memset(cnt, 0, 26 * sizeof(int));
            int alphaCnt = 0; // s[j+1, i] 出现不同的字符数
            int maxFreq = 0;  // s[j+1, i] 字符的最大次数
            for (int j = i - 1; j >= 0; j--)
            {
                cnt[s[j] - 'a']++;
                if (cnt[s[j] - 'a'] == 1)
                    alphaCnt++;
                maxFreq = max(maxFreq, cnt[s[j] - 'a']);
                if (alphaCnt * maxFreq == i - j)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end
