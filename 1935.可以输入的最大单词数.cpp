/*
 * @lc app=leetcode.cn id=1935 lang=cpp
 *
 * [1935] 可以输入的最大单词数
 */

// @lc code=start
class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        unordered_set<char> broken;
        for (char c : brokenLetters)
            broken.insert(c);
        istringstream iss(text);
        string word;
        int count = 0;
        while (iss >> word)
        {
            bool judge = true;
            for (char c : word)
                if (broken.count(c))
                {
                    judge = false;
                    break;
                }
            if (judge)
                count++;
        }
        return count;
    }
};
// @lc code=end
