/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution
{
private:
    const vector<string> Thousands = {"", "M", "MM", "MMM"};
    const vector<string> Hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const vector<string> Tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const vector<string> Units = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

public:
    string intToRoman(int num)
    {
        // 1 <= num <= 3999
        int unit = num % 10;
        num /= 10;
        int ten = num % 10;
        num /= 10;
        int hundred = num % 10;
        num /= 10;
        int thousand = num % 10;
        return Thousands[thousand] + Hundreds[hundred] + Tens[ten] + Units[unit];
    }
};
// @lc code=end
