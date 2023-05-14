/*
 * @lc app=leetcode.cn id=2273 lang=cpp
 *
 * [2273] 移除字母异位词后的结果数组
 */

// @lc code=start
class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> res = {words[0]}; // 结果数组
        int n = words.size();
        // 判断两个单词是否为字母异位词
        auto compare = [](const string &word1, const string &word2) -> bool
        {
            vector<int> freq(26);
            for (char ch : word1)
            {
                ++freq[ch - 'a'];
            }
            for (char ch : word2)
            {
                --freq[ch - 'a'];
            }
            return all_of(freq.begin(), freq.end(), [](int x)
                          { return x == 0; });
        };

        for (int i = 1; i < n; ++i)
        {
            if (compare(words[i], words[i - 1]))
            {
                continue;
            }
            res.push_back(words[i]);
        }
        return res;
    }
};
// @lc code=end
