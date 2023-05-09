/*
 * @lc app=leetcode.cn id=2578 lang=cpp
 *
 * [2578] 最小和分割
 */

// @lc code=start
class Solution
{
public:
    int splitNum(int num)
    {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int num1 = 0, num2 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int x = s[i] - '0';
            if (i % 2 == 0)
                num1 = 10 * num1 + x;
            else
                num2 = 10 * num2 + x;
        }
        return num1 + num2;
    }
};
// @lc code=end
