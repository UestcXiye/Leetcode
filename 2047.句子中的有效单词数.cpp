/*
 * @lc app=leetcode.cn id=2047 lang=cpp
 *
 * [2047] 句子中的有效单词数
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string word)
    {
        int n = word.size();
        int count = 0; // 连字符个数
        for (int i = 0; i < n; i++)
        {
            if (isdigit(word[i]))
                return false;
            if (islower(word[i]))
                continue;
            if (word[i] == '-')
            {
                if (i == 0 || i == n - 1 || count == 1 || !islower(word[i - 1]) || !islower(word[i + 1]))
                    return false;
                else
                {
                    count++;
                    continue;
                }
            }
            if ((word[i] == '!' || word[i] == '.' || word[i] == ',') && i != n - 1)
                return false;
        }
        return true;
    }
    int countValidWords(string sentence)
    {
        int ans = 0;
        istringstream iss(sentence);
        string word;
        while (iss >> word)
        {
            if (isValid(word))
                ans++;
        }
        return ans;
    }
};
// @lc code=end
