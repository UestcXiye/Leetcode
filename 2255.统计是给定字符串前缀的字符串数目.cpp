/*
 * @lc app=leetcode.cn id=2255 lang=cpp
 *
 * [2255] 统计是给定字符串前缀的字符串数目
 */

// @lc code=start
class Solution
{
public:
    int countPrefixes(vector<string> &words, string s)
    {
        int ans = 0;
        for (string word : words)
            if (s.substr(0, word.size()) == word)
                ans++;
        return ans;
    }
};
// @lc code=end
