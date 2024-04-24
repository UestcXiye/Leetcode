/*
 * @lc app=leetcode.cn id=3120 lang=cpp
 *
 * [3120] 统计特殊字母的数量 I
 */

// @lc code=start
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        vector<bool> lower(26, 0), upper(26, 0);
        for (char &c : word)
        {
            if (islower(c))
                lower[c - 'a'] = true;
            else
                upper[c - 'A'] = true;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            if (lower[i] && upper[i])
                cnt++;
        return cnt;
    }
};
// @lc code=end
