/*
 * @lc app=leetcode.cn id=2299 lang=cpp
 *
 * [2299] 强密码检验器 II
 */

// @lc code=start
class Solution
{
public:
    bool strongPasswordCheckerII(string password)
    {
        if (password.size() < 8)
            return false;
        for (int i = 0; i < password.size() - 1; i++)
            if (password[i] == password[i + 1])
                return false;
        unordered_set<char> specials = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        bool hasLowerAlpha = false, hasUpperAlpha = false;
        bool hasDigit = false;
        bool hasSpecial = false;
        for (char c : password)
        {
            if (islower(c))
                hasLowerAlpha = true;
            if (isupper(c))
                hasUpperAlpha = true;
            if (isdigit(c))
                hasDigit = true;
            if (specials.count(c))
                hasSpecial = true;
        }
        return hasLowerAlpha && hasUpperAlpha && hasDigit && hasSpecial;
    }
};
// @lc code=end
