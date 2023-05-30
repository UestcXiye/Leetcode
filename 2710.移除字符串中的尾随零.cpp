/*
 * @lc app=leetcode.cn id=2710 lang=cpp
 *
 * [2710] 移除字符串中的尾随零
 */

// @lc code=start
class Solution
{
public:
    string removeTrailingZeros(string num)
    {
        int i = num.size() - 1;
        while (num[i] == '0')
            i--;
        return num.substr(0, i + 1);
    }
};
// @lc code=end
