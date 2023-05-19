/*
 * @lc app=leetcode.cn id=1967 lang=cpp
 *
 * [1967] 作为子字符串出现在单词中的字符串数目
 */

// @lc code=start
class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int ans = 0;
        for (string s : patterns)
        {
            size_t pos = word.find(s);
            if (pos != string::npos)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
