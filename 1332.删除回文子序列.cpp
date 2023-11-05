/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 删除回文子序列
 */

// @lc code=start
class Solution
{
public:
    int removePalindromeSub(string s)
    {
        if (isPalindrome(s))
            return 1;
        return 2;
    }
    // 辅函数 - 判断字符串 s 是否回文
    bool isPalindrome(const string &s)
    {
        return s == string(s.rbegin(), s.rend());
    }
};
// @lc code=end
