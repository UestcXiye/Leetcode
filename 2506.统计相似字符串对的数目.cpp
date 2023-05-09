/*
 * @lc app=leetcode.cn id=2506 lang=cpp
 *
 * [2506] 统计相似字符串对的数目
 */

// @lc code=start
class Solution
{
public:
    string wordBits(string word)
    {
        string bits(26, '0');
        for (int i = 0; i < word.size(); i++)
            bits[word[i] - 'a'] = 1;
        return bits;
    }
    int similarPairs(vector<string> &words)
    {
        int ans = 0;
        int n = words.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (wordBits(words[i]) == wordBits(words[j]))
                    ans++;
        return ans;
    }
};
// @lc code=end
