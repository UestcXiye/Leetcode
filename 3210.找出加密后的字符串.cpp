/*
 * @lc app=leetcode.cn id=3210 lang=cpp
 *
 * [3210] 找出加密后的字符串
 */

// @lc code=start
class Solution
{
public:
    string getEncryptedString(string s, int k)
    {
        k %= s.size();
        string tmp1 = s.substr(0, k);
        string tmp2 = s.substr(k);
        return tmp2 + tmp1;
    }
};
// @lc code=end
