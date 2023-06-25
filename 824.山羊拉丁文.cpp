/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution
{
public:
    string toGoatLatin(string sentence)
    {
        istringstream iss(sentence);
        string s, ans;
        int count = 1;
        while (iss >> s)
        {
            if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' ||
                s[0] == 'A' || s[0] == 'E' || s[0] == 'I' || s[0] == 'O' || s[0] == 'U')
            {
                ans += s + "ma";
            }
            else
            {
                ans += s.substr(1) + s[0] + "ma";
            }
            for (int i = 0; i < count; i++)
                ans += "a";
            count++;
            ans += " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
};
// @lc code=end
