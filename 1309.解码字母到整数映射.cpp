/*
 * @lc app=leetcode.cn id=1309 lang=cpp
 *
 * [1309] 解码字母到整数映射
 */

// @lc code=start
class Solution
{
public:
    string freqAlphabets(string s)
    {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (i + 2 < n && s[i + 2] == '#')
            {
                ans += (char)('a' - 1 + stoi(s.substr(i, 2)));
                i += 2;
            }
            else
                ans += (char)('a' + s[i] - '1');
        }
        return ans;
    }
};
// @lc code=end
