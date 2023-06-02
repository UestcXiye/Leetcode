/*
 * @lc app=leetcode.cn id=1694 lang=cpp
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start
class Solution
{
public:
    string reformatNumber(string number)
    {
        vector<char> digits;
        for (char &c : number)
            if (isdigit(c))
                digits.push_back(c);
        int n = digits.size();
        int pt = 0;
        string ans;
        while (n > 0)
        {
            if (n > 4)
            {
                ans += digits[pt];
                ans += digits[pt + 1];
                ans += digits[pt + 2];
                ans += '-';
                pt += 3;
                n -= 3;
            }
            else
            {
                if (n == 4)
                {
                    ans += digits[pt];
                    ans += digits[pt + 1];
                    ans += '-';
                    ans += digits[pt + 2];
                    ans += digits[pt + 3];
                }
                else
                {
                    for (int i = pt; i < digits.size(); i++)
                        ans += digits[i];
                }
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
