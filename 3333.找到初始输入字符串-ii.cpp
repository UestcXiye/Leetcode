/*
 * @lc app=leetcode.cn id=3333 lang=cpp
 *
 * [3333] 找到初始输入字符串 II
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1'000'000'007;

public:
    int possibleStringCount(string word, int k)
    {
        int n = word.length();
        if (n < k)
            return 0;

        vector<int> cnts;
        long long ans = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt++;
            if (i == n - 1 || word[i] != word[i + 1])
            {
                if (cnts.size() < k)
                    cnts.push_back(cnt);
                ans = ans * cnt % MOD;
                cnt = 0;
            }
        }

        int m = cnts.size();
        if (m >= k) // 任何输入的字符串都至少为 k
            return ans;

        vector<vector<int>> dp(m + 1, vector<int>(k));
        // 初始化
        dp[0][0] = 1;
        vector<int> s(k + 1);
        // 状态转移
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < k; j++)
                s[j + 1] = (s[j] + dp[i][j]) % MOD;
            // j <= i 的 dp[i][j] 都是 0
            for (int j = i + 1; j < k; j++)
                dp[i + 1][j] = (s[j] - s[max(j - cnts[i], 0)]) % MOD;
        }

        ans -= reduce(dp[m].begin() + m, dp[m].end(), 0LL);
        return (ans % MOD + MOD) % MOD; // 保证结果非负
    }
};
// @lc code=end
