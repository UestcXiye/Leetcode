/*
 * @lc app=leetcode.cn id=2119 lang=cpp
 *
 * [2119] 反转两次的数字
 */

// @lc code=start
class Solution
{
public:
    bool isSameAfterReversals(int num)
    {
        string s = to_string(num);
        string reversed1(s.rbegin(), s.rend());
        int rev1 = stoi(reversed1);
        reversed1 = to_string(rev1);
        string reversed2(reversed1.rbegin(), reversed1.rend());
        int rev2 = stoi(reversed2);
        reversed2 = to_string(rev2);
        return num == stoi(reversed2);
    }
};
// @lc code=end
