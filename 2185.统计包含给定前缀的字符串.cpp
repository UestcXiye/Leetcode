/*
 * @lc app=leetcode.cn id=2185 lang=cpp
 *
 * [2185] 统计包含给定前缀的字符串
 */

// @lc code=start
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int ans = 0;
        for (string word : words)
        {
            if (word.substr(0, pref.size()) == pref)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
