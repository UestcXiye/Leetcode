/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 *
 * [3090] 每个字符最多出现两次的最长子字符串
 */

// @lc code=start
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.length();
        vector<int> cnt(26, 0);
        int maxLen = 0;
        bool flag = true;
        for (int i = 0, j = 0; i < n; i++)
        {
            if (++cnt[s[i] - 'a'] >= 3)
                flag = false;
            while (j <= i && flag == false)
            {
                if (--cnt[s[j] - 'a'] == 2)
                    flag = true;
                j++;
            }
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};
// @lc code=end
