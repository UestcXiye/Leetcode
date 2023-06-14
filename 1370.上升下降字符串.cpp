/*
 * @lc app=leetcode.cn id=1370 lang=cpp
 *
 * [1370] 上升下降字符串
 */

// @lc code=start
class Solution
{
public:
    string sortString(string s)
    {
        vector<int> alpha(26, 0);
        for (char &c : s)
            alpha[c - 'a']++;
        string ans;
        while (ans.size() < s.size())
        {
            for (int i = 0; i < 26; i++)
            {
                if (alpha[i])
                {
                    ans.push_back(i + 'a');
                    alpha[i]--;
                }
            }
            for (int i = 25; i >= 0; i--)
            {
                if (alpha[i])
                {
                    ans.push_back(i + 'a');
                    alpha[i]--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
