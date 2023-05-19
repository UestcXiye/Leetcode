/*
 * @lc app=leetcode.cn id=2000 lang=cpp
 *
 * [2000] 反转单词前缀
 */

// @lc code=start
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int index = 0;
        for (int i = 0; i < word.size(); i++)
            if (word[i] == ch)
            {
                index = i;
                break;
            }
        reverse(word.begin(), word.begin() + index + 1);
        return word;
    }
};
// @lc code=end
