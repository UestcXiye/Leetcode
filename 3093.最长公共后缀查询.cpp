/*
 * @lc app=leetcode.cn id=3093 lang=cpp
 *
 * [3093] 最长公共后缀查询
 */

// @lc code=start

// 字典树

struct Trie
{
    Trie *child[26]{};
    int minLen = INT_MAX; // 匹配字符串的最小长度
    int index = 0;        // 匹配字符串在 wordsContainer 里的下标
};

class Solution
{
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        Trie *root = new Trie();
        for (int i = 0; i < wordsContainer.size(); i++)
        {
            string &s = wordsContainer[i];
            int len = s.length();
            auto cur = root;
            // 如果当前字符串长度小于当前节点记录的最小长度，更新最小长度和下标
            if (len < cur->minLen)
            {
                cur->minLen = len;
                cur->index = i;
            }
            // 逆序建立字典树
            for (int j = len - 1; j >= 0; j--)
            {
                int idx = s[j] - 'a';
                if (!cur->child[idx])
                    cur->child[idx] = new Trie();
                cur = cur->child[idx];
                // 如果当前字符串长度小于当前节点记录的最小长度，更新最小长度和下标
                if (len < cur->minLen)
                {
                    cur->minLen = len;
                    cur->index = i;
                }
            }
        }
        vector<int> ans;
        for (string &word : wordsQuery)
        {
            auto cur = root;
            for (int i = word.length() - 1; i >= 0 && cur->child[word[i] - 'a']; i--)
                cur = cur->child[word[i] - 'a'];
            ans.push_back(cur->index);
        }
        return ans;
    }
};
// @lc code=end
