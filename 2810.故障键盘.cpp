/*
 * @lc app=leetcode.cn id=2810 lang=cpp
 *
 * [2810] 故障键盘
 */

// @lc code=start
class Solution
{
public:
    string finalString(string s)
    {
        string ans;
        for (char &c : s)
        {
            if (c == 'i')
                reverse(ans.begin(), ans.end());
            else
                ans += c;
        }
        return ans;
    }
};
// @lc code=end
