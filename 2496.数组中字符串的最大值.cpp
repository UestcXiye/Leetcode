/*
 * @lc app=leetcode.cn id=2496 lang=cpp
 *
 * [2496] 数组中字符串的最大值
 */

// @lc code=start
class Solution
{
public:
    bool isNumString(string s)
    {
        for (int i = 0; i < s.size(); i++)
            if (!isdigit(s[i]))
                return false;
        return true;
    }
    int maximumValue(vector<string> &strs)
    {
        int ans = 0;
        for (string str : strs)
        {
            int len;
            if (isNumString(str))
                len = stoi(str);
            else
                len = str.size();
            ans = max(ans, len);
        }
        return ans;
    }
};
// @lc code=end
