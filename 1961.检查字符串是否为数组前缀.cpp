/*
 * @lc app=leetcode.cn id=1961 lang=cpp
 *
 * [1961] 检查字符串是否为数组前缀
 */

// @lc code=start
class Solution
{
public:
    bool isPrefixString(string s, vector<string> &words)
    {
        string temp;
        for (string word : words)
        {
            temp.append(word);
            if (temp == s)
                return true;
        }
        return false;
    }
};
// @lc code=end
