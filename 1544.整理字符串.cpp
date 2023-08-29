/*
 * @lc app=leetcode.cn id=1544 lang=cpp
 *
 * [1544] 整理字符串
 */

// @lc code=start
class Solution
{
public:
    string makeGood(string s)
    {
        string ans;
        for (char &c : s)
        {
            if (!ans.empty() && (ans.back() == c + 32 || ans.back() == c - 32))
                ans.pop_back();
            else
                ans.push_back(c);
        }
        return ans;
    }
};
// @lc code=end
