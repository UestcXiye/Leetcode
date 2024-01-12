/*
 * @lc app=leetcode.cn id=2085 lang=cpp
 *
 * [2085] 统计出现过一次的公共字符串
 */

// @lc code=start
class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<string, int> umap1, umap2;
        for (const string &word : words1)
            umap1[word]++;
        for (const string &word : words2)
            umap2[word]++;
        int ans = 0;
        for (auto &[str, cnt] : umap1)
            if (cnt == 1 && umap2[str] == 1)
                ans++;
        return ans;
    }
};
// @lc code=end
