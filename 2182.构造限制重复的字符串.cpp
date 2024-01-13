/*
 * @lc app=leetcode.cn id=2182 lang=cpp
 *
 * [2182] 构造限制重复的字符串
 */

// @lc code=start
class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        // 特判
        if (s.empty() || repeatLimit <= 0)
            return "";
            
        vector<int> cnt(26, 0);
        for (char &c : s)
            cnt[c - 'a']++;

        string ans;
        int cur = 0;
        for (int i = 25, j = 24; i >= 0 && j >= 0;)
        {
            if (cnt[i] == 0) // 当前字符已经填完，填入后面的字符，重置 cur
            {
                i--;
                cur = 0;
            }
            else if (cur < repeatLimit)
            {
                ans.push_back('a' + i);
                cur++;
                cnt[i]--;
            }
            else if (j >= i || cnt[j] == 0)
            {
                j--;
            }
            else // 当前字符已经超过限制，填入其他字符，并且重置 cur
            {
                ans.push_back('a' + j);
                cnt[j]--;
                cur = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
