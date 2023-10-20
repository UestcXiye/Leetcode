/*
 * @lc app=leetcode.cn id=2864 lang=cpp
 *
 * [2864] 最大二进制奇数
 */

// @lc code=start
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int n = s.size(), count_one = 0;
        for (char &c : s)
            if (c == '1')
                count_one++;
        string ans;
        for (int i = 0; i < count_one - 1; i++)
            ans += '1';
        for (int i = 0; i < n - count_one; i++)
            ans += '0';
        ans += '1';
        return ans;
    }
};
// @lc code=end
