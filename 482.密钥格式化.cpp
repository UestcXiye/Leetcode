/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        vector<char> v;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != '-')
            {
                if (islower(s[i]))
                    v.push_back(toupper(s[i]));
                else
                    v.push_back(s[i]);
            }
        string ans;
        int count = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans += v[i];
            count++;
            if (count == k)
            {
                if (i != 0)
                    ans += "-";
                count = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
