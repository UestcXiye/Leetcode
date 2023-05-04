/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string temp;
        while (columnNumber)
        {
            columnNumber -= 1;
            temp += 'A' + columnNumber % 26;
            columnNumber /= 26;
        }
        return string(temp.rbegin(), temp.rend());
    }
};
// @lc code=end
