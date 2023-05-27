/*
 * @lc app=leetcode.cn id=1763 lang=cpp
 *
 * [1763] 最长的美好子字符串
 */

// @lc code=start
class Solution
{
private:
    bool isBeautiful(string &str)
    {
        vector<int> lowerAlpha(26, 0), upperAlpha(26, 0);
        for (char &c : str)
        {
            if (islower(c))
                lowerAlpha[c - 'a'] = 1;
            else
                upperAlpha[c - 'A'] = 1;
        }
        for (int i = 0; i < 26; i++)
            if (lowerAlpha[i] ^ upperAlpha[i])
                return false;
        return true;
    }

public:
    string longestNiceSubstring(string s)
    {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++)
            for (int len = 1; len <= n - i; len++)
            {
                string temp = s.substr(i, len);
                if (isBeautiful(temp) && temp.size() > ans.size())
                    ans = temp;
            }
        return ans;
    }
};
// @lc code=end
