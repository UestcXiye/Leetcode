/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution
{
public:
    bool isVowelString(string s)
    {
        string vowel = "aeiou";
        if (vowel.find(s[0]) != string::npos && vowel.find(s[s.size() - 1]) != string::npos)
            return true;
        else
            return false;
    }
    int vowelStrings(vector<string> &words, int left, int right)
    {
        int count = 0;
        for (int i = left; i <= right; i++)
            if (isVowelString(words[i]))
                count++;
        return count;
    }
};
// @lc code=end
