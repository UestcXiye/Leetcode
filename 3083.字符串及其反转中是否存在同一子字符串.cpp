/*
 * @lc app=leetcode.cn id=3083 lang=cpp
 *
 * [3083] 字符串及其反转中是否存在同一子字符串
 */

// @lc code=start
class Solution
{
public:
    bool isSubstringPresent(string s)
    {
        int n = s.length();
        for (int i = 0; i < n - 1; i++)
        {
            string t1 = s.substr(i, 2);
            for (int j = n - 1; j > 0; j--)
            {
                string t2 = s.substr(j - 1, 2);
                reverse(t2.begin(), t2.end());
                if (t1 == t2)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
