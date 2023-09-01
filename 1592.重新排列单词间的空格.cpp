/*
 * @lc app=leetcode.cn id=1592 lang=cpp
 *
 * [1592] 重新排列单词间的空格
 */

// @lc code=start
class Solution
{
public:
    string reorderSpaces(string text)
    {
        int space = 0;
        for (char &c : text)
            if (c == ' ')
                space++;
        istringstream is(text);
        string word;
        vector<string> words;
        while (is >> word)
            words.push_back(word);
        // 特判
        if (words.size() == 1)
            return words[0] + string(space, ' ');
        string ans;
        int step = space / (words.size() - 1);
        for (int i = 0; i < words.size(); i++)
        {
            ans += words[i];
            if (i != words.size() - 1)
                for (int i = 0; i < step; i++)
                    ans += " ";
        }
        for (int i = 0; i < space % (words.size() - 1); i++)
            ans += " ";
        return ans;
    }
};
// @lc code=end
