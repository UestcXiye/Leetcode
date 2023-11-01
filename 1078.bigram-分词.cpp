/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

// @lc code=start
class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        istringstream iss(text);
        vector<string> words;
        string word;
        while (iss >> word)
            words.push_back(word);

        int n = words.size();
        vector<string> ans;
        for (int i = 1; i < n; i++)
            if (words[i] == second && words[i - 1] == first && i + 1 < n)
                ans.push_back(words[i + 1]);
        return ans;
    }
};
// @lc code=end
