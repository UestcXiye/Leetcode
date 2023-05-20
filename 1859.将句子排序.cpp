/*
 * @lc app=leetcode.cn id=1859 lang=cpp
 *
 * [1859] 将句子排序
 */

// @lc code=start
class Solution
{
private:
    static bool cmp(const string A, const string B)
    {
        return A[A.size() - 1] < B[B.size() - 1];
    }

public:
    string sortSentence(string s)
    {
        istringstream iss(s);
        string word;
        vector<string> words;
        while (iss >> word)
            words.push_back(word);
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        string ans;
        for (int i = 0; i < n; i++)
        {
            ans.append(words[i].substr(0, words[i].size() - 1));
            if (i != n - 1)
                ans += " ";
        }
        return ans;
    }
};
// @lc code=end
