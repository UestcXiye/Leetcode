/*
 * @lc app=leetcode.cn id=1880 lang=cpp
 *
 * [1880] 检查某单词是否等于两单词之和
 */

// @lc code=start
class Solution
{
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        string first, second, target;
        for (int i = 0; i < firstWord.size(); i++)
            first.push_back(firstWord[i] - 'a' + '0');
        for (int i = 0; i < secondWord.size(); i++)
            second.push_back(secondWord[i] - 'a' + '0');
        for (int i = 0; i < targetWord.size(); i++)
            target.push_back(targetWord[i] - 'a' + '0');
        return stoi(first) + stoi(second) == stoi(target);
    }
};
// @lc code=end
