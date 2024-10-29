/*
 * @lc app=leetcode.cn id=3324 lang=cpp
 *
 * [3324] 出现在屏幕上的字符串序列
 */

// @lc code=start
class Solution
{
public:
    vector<string> stringSequence(string target)
    {
        if (target.empty())
            return {};

        string s;
        vector<string> ans;
        for (int i = 0; i < target.length(); i++)
        {
            s.push_back('a');
            for (char c = 'a'; c <= target[i]; c++)
            {
                s.back() = c;
                ans.push_back(s);
            }
        }

        return ans;
    }
};
// @lc code=end
