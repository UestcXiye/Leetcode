/*
 * @lc app=leetcode.cn id=2544 lang=cpp
 *
 * [2544] 交替数字和
 */

// @lc code=start
class Solution
{
public:
    int alternateDigitSum(int n)
    {
        string s = to_string(n);
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
                sum += s[i] - '0';
            else
                sum -= s[i] - '0';
        }
        return sum;
    }
};
// @lc code=end
