/*
 * @lc app=leetcode.cn id=1903 lang=cpp
 *
 * [1903] 字符串中的最大奇数
 */

// @lc code=start
class Solution
{
public:
    string largestOddNumber(string num)
    {
        for (int i = num.size() - 1; i >= 0; i--)
            if ((num[i] - '0') % 2)
                return num.substr(0, i + 1);
        return "";
    }
};
// @lc code=end
