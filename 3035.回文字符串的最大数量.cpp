/*
 * @lc app=leetcode.cn id=3035 lang=cpp
 *
 * [3035] 回文字符串的最大数量
 */

// @lc code=start

// 哈希 + 贪心 + 排序

class Solution
{
public:
    int maxPalindromesAfterOperations(vector<string> &words)
    {
        // 特判
        if (words.empty())
            return 0;

        int n = words.size();
        int total = 0; // 出现次数为偶数的字母总数
        unordered_map<char, int> mp;

        for (string &word : words)
        {
            total += word.length();
            for (char &c : word)
                mp[c]++;
        }

        // 减去出现次数为奇数的字母
        for (auto &[ch, cnt] : mp)
            total -= cnt % 2;

        sort(words.begin(), words.end(), [](const string &s1, const string &s2)
             { return s1.length() < s2.length(); });

        int ans = 0;
        for (string &word : words)
        {
            int len = word.length();
            // 长为奇数的字符串，长度要减一
            total -= len % 2 == 1 ? len - 1 : len;
            if (total < 0)
                break;
            ans++;
        }

        return ans;
    }
};
// @lc code=end
