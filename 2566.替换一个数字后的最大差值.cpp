/*
 * @lc app=leetcode.cn id=2566 lang=cpp
 *
 * [2566] 替换一个数字后的最大差值
 */

// @lc code=start
class Solution
{
public:
    string transToMax(string s)
    {
        string temp = s;
        int index = 0;
        while (s[index] == '9')
            index++;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == s[index])
                temp[i] = '9';
        return temp;
    }
    string transToMin(string s)
    {
        string temp = s;
        char c = s[0];
        for (int i = 0; i < s.size(); i++)
            if (s[i] == c)
                temp[i] = '0';
        return temp;
    }
    int strToNum(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
            sum = 10 * sum + s[i] - '0';
        return sum;
    }
    int minMaxDifference(int num)
    {
        string s = to_string(num);
        return strToNum(transToMax(s)) - strToNum(transToMin(s));
    }
};
// @lc code=end
