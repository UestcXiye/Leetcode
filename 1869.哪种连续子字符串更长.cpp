/*
 * @lc app=leetcode.cn id=1869 lang=cpp
 *
 * [1869] 哪种连续子字符串更长
 */

// @lc code=start
class Solution
{
public:
    bool checkZeroOnes(string s)
    {
        int len1 = 0, len0 = 0;
        int max1 = 0, max0 = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                len0++;
                len1 = 0;
            }
            else
            {
                len1++;
                len0 = 0;
            }
            max1 = max(len1, max1);
            max0 = max(len0, max0);
        }
        return max1 > max0;
    }
};
// @lc code=end
