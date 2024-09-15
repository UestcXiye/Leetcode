/*
 * @lc app=leetcode.cn id=3280 lang=cpp
 *
 * [3280] 将日期转换为二进制表示
 */

// @lc code=start
class Solution
{
public:
    string convertDateToBinary(string date)
    {
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8);
        return trans(year) + "-" + trans(month) + "-" + trans(day);
    }
    // 辅函数 - 转成二进制字符串
    string trans(string &s)
    {
        int x = stoi(s);
        string res;
        while (x)
        {
            res.insert(res.begin(), x % 2 + '0');
            x /= 2;
        }
        return res;
    }
};
// @lc code=end
