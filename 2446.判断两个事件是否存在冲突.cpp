/*
 * @lc app=leetcode.cn id=2446 lang=cpp
 *
 * [2446] 判断两个事件是否存在冲突
 */

// @lc code=start
class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        int startH1 = 10 * (event1[0][0] - '0') + event1[0][1] - '0';
        int startM1 = 10 * (event1[0][3] - '0') + event1[0][4] - '0';
        int endH1 = 10 * (event1[1][0] - '0') + event1[1][1] - '0';
        int endM1 = 10 * (event1[1][3] - '0') + event1[1][4] - '0';

        int startH2 = 10 * (event2[0][0] - '0') + event2[0][1] - '0';
        int startM2 = 10 * (event2[0][3] - '0') + event2[0][4] - '0';
        int endH2 = 10 * (event2[1][0] - '0') + event2[1][1] - '0';
        int endM2 = 10 * (event2[1][3] - '0') + event2[1][4] - '0';

        if (startH2 > endH1 || (startH2 == endH1 && startM2 > endM1))
            return false;
        if (startH1 > endH2 || (startH1 == endH2 && startM1 > endM2))
            return false;
        return true;
    }
};
// @lc code=end
