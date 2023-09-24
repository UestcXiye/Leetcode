/*
 * @lc app=leetcode.cn id=8048 lang=cpp
 *
 * [8048] 最大二进制奇数
 */

// @lc code=start
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int one = 0;
        for (char &c : s)
            if (c == '1')
                one++;
        string ans;
        for (int i = 0; i < one - 1; i++)
            ans += '1';
        for (int i = 0; i < s.size() - one; i++)
            ans += '0';
        ans += '1';
        return ans;
    }
};
// @lc code=end
