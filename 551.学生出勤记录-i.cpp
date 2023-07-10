/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution
{
public:
    bool checkRecord(string s)
    {
        int absent = 0;
        for (char &c : s)
            if (c == 'A')
                absent++;
        if (absent >= 2 || s.find("LLL") != string::npos)
            return false;
        return true;
    }
};
// @lc code=end
