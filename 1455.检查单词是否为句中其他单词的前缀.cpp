/*
 * @lc app=leetcode.cn id=1455 lang=cpp
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

// @lc code=start
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        istringstream iss(sentence);
        string s;
        int count = 1;
        while (iss >> s)
        {
            if (searchWord == s.substr(0, searchWord.size()))
                return count;
            else
                count++;
        }
        return -1;
    }
};
// @lc code=end
