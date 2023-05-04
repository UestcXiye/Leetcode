/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word)
            words.push_back(word);
        if (pattern.size() != words.size())
            return false;
        unordered_map<char, string> umap1;
        unordered_map<string, char> umap2;
        int n = pattern.size();
        for (int i = 0; i < n; i++)
        {
            char ch = pattern[i];
            word = words[i];
            if (!umap1.count(ch))
                umap1.insert(pair<char, string>(ch, word));
            else if (umap1[ch] != word)
                return false;
            if (!umap2.count(word))
                umap2.insert(pair<string, char>(word, ch));
            else if (umap2[word] != ch)
                return false;
        }
        return true;
    }
};
// @lc code=end
