/*
 * @lc app=leetcode.cn id=3136 lang=cpp
 *
 * [3136] 有效单词
 */

// @lc code=start
class Solution
{
private:
    bool isYuan(char &c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }

public:
    bool isValid(string word)
    {
        if (word.length() < 3)
            return false;
        bool digit = false, upper = false, lower = false;
        int cntYuan = 0, cntNotYuan = 0;
        for (char &c : word)
        {
            if (isdigit(c))
                digit = true;
            else if (isupper(c))
                upper = true;
            else if (islower(c))
                lower = true;
            else
                return false;
            if (isYuan(c))
                cntYuan++;
            if ((isupper(c) || islower(c)) && !isYuan(c))
                cntNotYuan++;
        }
        return (digit || upper || lower) && cntYuan > 0 && cntNotYuan > 0;
    }
};
// @lc code=end
