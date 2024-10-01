/*
 * @lc app=leetcode.cn id=3298 lang=cpp
 *
 * [3298] 统计重新排列后包含另一个字符串的子字符串数目 II
 */

// @lc code=start
class Solution
{
public:
    long long validSubstringCount(string word1, string word2)
    {
        vector<int> cnt(26, 0);
        for (char &c : word2)
            cnt[c - 'a']--;
        int shortage = 0;
        for (int i = 0; i < 26; i++)
            if (cnt[i] < 0)
                shortage++;

        int len1 = word1.size();
        long long ans = 0LL;
        for (int left = 0, right = 0; left < len1; left++)
        {
            while (right < len1 && shortage > 0)
            {
                cnt[word1[right] - 'a']++;
                if (cnt[word1[right] - 'a'] == 0)
                    shortage--;
                right++;
            }

            if (shortage == 0)
                ans += len1 - right + 1;

            cnt[word1[left] - 'a']--;
            if (cnt[word1[left] - 'a'] == -1)
                shortage++;
        }

        return ans;
    }
};
// @lc code=end
