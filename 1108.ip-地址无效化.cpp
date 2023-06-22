/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
class Solution
{
public:
    string defangIPaddr(string address)
    {
        string ans;
        for (char &c : address)
        {
            if (c == '.')
                ans += "[.]";
            else
                ans += c;
        }
        return ans;
    }
};
// @lc code=end
