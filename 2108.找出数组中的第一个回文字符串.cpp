/*
 * @lc app=leetcode.cn id=2108 lang=cpp
 *
 * [2108] 找出数组中的第一个回文字符串
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        return s == string(s.rbegin(), s.rend());
    }
    string firstPalindrome(vector<string> &words)
    {
        for (string word : words)
            if (isPalindrome(word))
                return word;
        return "";
    }
};
// @lc code=end
