/*
 * @lc app=leetcode.cn id=3335 lang=cpp
 *
 * [3335] 字符串转换后的长度 I
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int lengthAfterTransformations(string s, int t)
    {
        vector<int> cnt(26, 0);
        for (char &c : s)
            cnt[c - 'a']++;

        while (t--)
        {
            vector<int> nxt(26, 0);
            for (int i = 0; i < 26; i++)
                nxt[(i + 1) % 26] = cnt[i] % MOD;
            nxt[1] = (nxt[1] + cnt[25]) % MOD;

            cnt = nxt;
        }

        long long ans = 0ll;
        for (int i = 0; i < 26; i++)
            ans = (ans + cnt[i]) % MOD;
        return ans;
    }
};
// @lc code=end
