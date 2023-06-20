/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

// @lc code=start
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> freq;
        istringstream iss1(s1), iss2(s2);
        string s;
        while (iss1 >> s)
            freq[s]++;
        while (iss2 >> s)
            freq[s]++;
        vector<string> ans;
        for (const auto &[word, count] : freq)
            if (count == 1)
                ans.push_back(word);
        return ans;
    }
};
// @lc code=end
