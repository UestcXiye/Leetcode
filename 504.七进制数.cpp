/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        int n = abs(num);
        string ans;
        while (n)
        {
            ans += '0' + n % 7;
            n /= 7;
        }
        if (num < 0)
            ans += "-";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
