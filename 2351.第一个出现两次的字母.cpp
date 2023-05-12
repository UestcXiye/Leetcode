/*
 * @lc app=leetcode.cn id=2351 lang=cpp
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start
class Solution
{
public:
    char repeatedCharacter(string s)
    {
        int count[26];
        char ans;
        memset(count, 0, 26 * sizeof(int));
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] == 2)
            {
                ans = s[i];
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
