/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start
class Solution
{
private:
    int countVowel(string str)
    {
        int count = 0;
        for (char &c : str)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                count++;
        }
        return count;
    }

public:
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        return countVowel(s.substr(0, n / 2)) == countVowel(s.substr(n / 2, n / 2));
    }
};
// @lc code=end
